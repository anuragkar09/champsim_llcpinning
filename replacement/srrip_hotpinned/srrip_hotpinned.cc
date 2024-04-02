#include "cache.h"

#define maxRRPV 3

// initialize replacement state
void CACHE::initialize_replacement()
{
  for (auto& blk : block)
    blk.lru = maxRRPV;
}

// find replacement victim
uint32_t CACHE::find_victim(uint32_t cpu, uint64_t instr_id, uint32_t set, const BLOCK* current_set, uint64_t ip, uint64_t full_addr, uint32_t type)
{
  // look for the maxRRPV line
  auto begin = std::next(std::begin(block), set * NUM_WAY);
  uint64_t max_way = get_max_way(set);
  auto end = std::next(begin, max_way);

  uint64_t ro, ba, ra, ch, CRA_idx;

  for (auto it = begin; it != end; ++it){
    ro = dram_get_row(it->address);
    ba = dram_get_bank(it->address);
    ra = dram_get_rank(it->address);
    ch = dram_get_channel(it->address);

    CRA_idx = ro * (DRAM_CHANNELS * DRAM_BANKS * DRAM_RANKS)
                        + ra * (DRAM_CHANNELS * DRAM_BANKS)
                        + ba * (DRAM_CHANNELS)
                        + ch;
    if (CRA_ctr[CRA_idx] >= RH_THRESHOLD/4){  
      it->lru = 0;
    }
  }

  auto victim = std::find_if(begin, end, [](BLOCK x) { return x.lru == maxRRPV; }); // hijack the lru field
  while (victim == end) {

    for (auto it = begin; it != end; ++it){
      it->lru++;

      if(Num_Hot_Rows>0)
      {
        ro = dram_get_row(it->address);
        ba = dram_get_bank(it->address);
        ra = dram_get_rank(it->address);
        ch = dram_get_channel(it->address);

        CRA_idx = ro * (DRAM_CHANNELS * DRAM_BANKS * DRAM_RANKS)
                          + ra * (DRAM_CHANNELS * DRAM_BANKS)
                          + ba * (DRAM_CHANNELS)
                          + ch;
        if(CRA_ctr[CRA_idx] >= RH_THRESHOLD/2){
          it->lru = 0;
        }
      }
    }
    victim = std::find_if(begin, end, [](BLOCK x) { return x.lru == maxRRPV; });
  }

  return std::distance(begin, victim);
}

// called on every cache hit and cache fill
void CACHE::update_replacement_state(uint32_t cpu, uint32_t set, uint32_t way, uint64_t full_addr, uint64_t ip, uint64_t victim_addr, uint32_t type,
                                     uint8_t hit)
{
  if (hit)
    block[set * NUM_WAY + way].lru = 0;
  else
    block[set * NUM_WAY + way].lru = maxRRPV - 1;
}

// use this function to print out your own stats at the end of simulation
void CACHE::replacement_final_stats() {}

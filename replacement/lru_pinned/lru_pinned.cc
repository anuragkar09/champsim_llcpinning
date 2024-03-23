#include <algorithm>
#include <iterator>

#include "cache.h"
#include "util.h"

void CACHE::initialize_replacement() {}

// find replacement victim
uint32_t CACHE::find_victim(uint32_t cpu, uint64_t instr_id, uint32_t set, const BLOCK* current_set, uint64_t ip, uint64_t full_addr, uint32_t type)
{
  // baseline LRU
  auto dist = std::distance(current_set, std::max_element(current_set, std::next(current_set, NUM_WAY), lru_comparator<BLOCK, BLOCK>()));
  BLOCK* copy_set = (BLOCK*)malloc(sizeof(BLOCK) * NUM_WAY);
  std::copy(current_set, std::next(current_set, NUM_WAY), copy_set);

  int count = 0;
  while (current_set[dist].pinned) {
    //std::cout << "Pinned block found at way " << dist << std::endl;
    copy_set[dist].lru = 0;
    dist = std::distance(copy_set, std::max_element(copy_set, std::next(copy_set, NUM_WAY), lru_comparator<BLOCK, BLOCK>()));
    count++;
    if (count == 100000) {
      std::cout << "[DEADLOCK] DEADLOCK DETECTED" << std::endl;
    }
  }
  return dist;
}

// called on every cache hit and cache fill
void CACHE::update_replacement_state(uint32_t cpu, uint32_t set, uint32_t way, uint64_t full_addr, uint64_t ip, uint64_t victim_addr, uint32_t type,
                                     uint8_t hit)
{
  if (hit && type == WRITEBACK)
    return;

  auto begin = std::next(block.begin(), set * NUM_WAY);
  auto end = std::next(begin, NUM_WAY);
  uint32_t hit_lru = std::next(begin, way)->lru;
  std::for_each(begin, end, [hit_lru](BLOCK& x) {
    if (x.lru <= hit_lru)
      x.lru++;
  });
  std::next(begin, way)->lru = 0; // promote to the MRU position
}

void CACHE::replacement_final_stats() {}

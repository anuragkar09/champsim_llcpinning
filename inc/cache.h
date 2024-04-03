/*
 *    Copyright 2023 The ChampSim Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CACHE_H
#define CACHE_H

#include <functional>
#include <list>
#include <string>
#include <vector>
#include <unordered_set>
#include <cstring>
#include "champsim.h"
#include "delay_queue.hpp"
#include "memory_class.h"
#include "ooo_cpu.h"
#include "operable.h"

// virtual address space prefetching
#define VA_PREFETCH_TRANSLATION_LATENCY 2

extern std::array<O3_CPU*, NUM_CPUS> ooo_cpu;

class CACHE : public champsim::operable, public MemoryRequestConsumer, public MemoryRequestProducer
{
public:
  uint32_t cpu;
  const std::string NAME;
  const uint32_t NUM_SET, NUM_WAY, WQ_SIZE, RQ_SIZE, PQ_SIZE, MSHR_SIZE;
  const uint32_t HIT_LATENCY, FILL_LATENCY, OFFSET_BITS;
  std::vector<BLOCK> block{NUM_SET * NUM_WAY};
  const uint32_t MAX_READ, MAX_WRITE;
  uint32_t reads_available_this_cycle, writes_available_this_cycle;
  const bool prefetch_as_load;
  const bool match_offset_bits;
  const bool virtual_prefetch;
  bool ever_seen_data = false;
  const unsigned pref_activate_mask = (1 << static_cast<int>(LOAD)) | (1 << static_cast<int>(PREFETCH));

  uint64_t *CRA_ctr = NULL;
  uint64_t *CRA_ctr_set = NULL;
  uint64_t Num_Hot_Rows = 0; //++anurag
  uint64_t *per_set_tracker_state = NULL;
  bool     *isUniqRow = NULL;
  std::unordered_set<uint64_t> *cachedCtrs;

  uint64_t last_tracker_reset = 0;
  uint64_t rows_per_set = 0;
  uint64_t sets_in_state[4] = {0}; // state-0, state-1, state-2, state-3
  uint64_t uniq_rows_ACT = 0;
  uint64_t num_ACT = 0;
  uint64_t num_mits = 0;
  uint64_t row_ACT[100] = {};

  uint64_t s_resets = 0;
  uint64_t s_sets_in_state[4] = {0}; // state-0, state-1, state-2, state-3
  uint64_t s_uniq_rows_ACT = 0;
  uint64_t s_uniq_rows_touched = 0;
  uint64_t s_num_ACT = 0;
  uint64_t s_num_mits = 0;
  uint64_t s_num_mits_this_period = 0;
  uint64_t s_num_mits_last_period = 0;
  uint64_t s_num_mits_last_period_cum = 0;
  uint64_t s_policy = 0;
  uint64_t s_last_mit_cycle = 0;
  uint64_t s_mm_set_evicts = 0;
  uint64_t s_mm_set_misses = 0;
  uint64_t s_row_ACT[100] = {};
  uint64_t s_early_writebacks = 0;
  uint64_t s_ctr_way_data_wb = 0;
  uint64_t s_BH_num_delay = 0;
  uint64_t s_BH_sum_delay = 0;
  uint64_t s_BH_max_delay = 0;

  // prefetch stats
  uint64_t pf_requested = 0, pf_issued = 0, pf_useful = 0, pf_useless = 0, pf_fill = 0;

  // queues
  champsim::delay_queue<PACKET> RQ{RQ_SIZE, HIT_LATENCY}, // read queue
      PQ{PQ_SIZE, HIT_LATENCY},                           // prefetch queue
      VAPQ{PQ_SIZE, VA_PREFETCH_TRANSLATION_LATENCY},     // virtual address prefetch queue
      WQ{WQ_SIZE, HIT_LATENCY};                           // write queue

  std::list<PACKET> MSHR; // MSHR

  uint64_t sim_access[NUM_CPUS][NUM_TYPES] = {}, sim_hit[NUM_CPUS][NUM_TYPES] = {}, sim_miss[NUM_CPUS][NUM_TYPES] = {}, roi_access[NUM_CPUS][NUM_TYPES] = {},
           roi_hit[NUM_CPUS][NUM_TYPES] = {}, roi_miss[NUM_CPUS][NUM_TYPES] = {};

  uint64_t RQ_ACCESS = 0, RQ_MERGED = 0, RQ_FULL = 0, RQ_TO_CACHE = 0, PQ_ACCESS = 0, PQ_MERGED = 0, PQ_FULL = 0, PQ_TO_CACHE = 0, WQ_ACCESS = 0, WQ_MERGED = 0,
           WQ_FULL = 0, WQ_FORWARD = 0, WQ_TO_CACHE = 0;

  uint64_t total_miss_latency = 0;

  // functions
  int add_rq(PACKET* packet) override;
  int add_wq(PACKET* packet) override;
  int add_pq(PACKET* packet) override;

  void return_data(PACKET* packet) override;
  void operate() override;
  void operate_writes();
  void operate_reads();

  uint32_t get_occupancy(uint8_t queue_type, uint64_t address) override;
  uint32_t get_size(uint8_t queue_type, uint64_t address) override;


  uint64_t dram_get_channel(uint64_t address);
  uint64_t dram_get_rank(uint64_t address);
  uint64_t dram_get_bank(uint64_t address);
  uint64_t dram_get_row(uint64_t address);

  uint32_t get_set(uint64_t address);
  uint32_t get_way(uint64_t address, uint32_t set);
  uint32_t get_max_way(uint64_t set);
  uint32_t num_reserved_ways_in_state_3();
  void     free_up_ctr_ways(uint64_t set);

  int invalidate_entry(uint64_t inval_addr);
  int prefetch_line(uint64_t pf_addr, bool fill_this_level, uint32_t prefetch_metadata);
  int prefetch_line(uint64_t ip, uint64_t base_addr, uint64_t pf_addr, bool fill_this_level, uint32_t prefetch_metadata); // deprecated

  void add_mshr(PACKET* packet);
  void va_translate_prefetches();

  void handle_fill();
  void handle_writeback();
  void handle_read();
  void handle_prefetch();

  void readlike_hit(std::size_t set, std::size_t way, PACKET& handle_pkt);
  bool readlike_miss(PACKET& handle_pkt);
  bool filllike_miss(std::size_t set, std::size_t way, PACKET& handle_pkt);

  bool should_activate_prefetcher(int type);

  void print_deadlock() override;

  void recvACTInfo();
  void performRHActions();

#include "cache_modules.inc"

  const repl_t repl_type;
  const pref_t pref_type;

  // constructor
  CACHE(std::string v1, double freq_scale, unsigned fill_level, uint32_t v2, int v3, uint32_t v5, uint32_t v6, uint32_t v7, uint32_t v8, uint32_t hit_lat,
        uint32_t fill_lat, uint32_t max_read, uint32_t max_write, std::size_t offset_bits, bool pref_load, bool wq_full_addr, bool va_pref,
        unsigned pref_act_mask, MemoryRequestConsumer* ll, pref_t pref, repl_t repl)
      : champsim::operable(freq_scale), MemoryRequestConsumer(fill_level), MemoryRequestProducer(ll), NAME(v1), NUM_SET(v2), NUM_WAY(v3), WQ_SIZE(v5),
        RQ_SIZE(v6), PQ_SIZE(v7), MSHR_SIZE(v8), HIT_LATENCY(hit_lat), FILL_LATENCY(fill_lat), OFFSET_BITS(offset_bits), MAX_READ(max_read),
        MAX_WRITE(max_write), prefetch_as_load(pref_load), match_offset_bits(wq_full_addr), virtual_prefetch(va_pref), pref_activate_mask(pref_act_mask),
        repl_type(repl), pref_type(pref)
  {
    if (NAME == "LLC") {
      CRA_ctr = new uint64_t[DRAM_CHANNELS * DRAM_RANKS * DRAM_BANKS * DRAM_ROWS];
      CRA_ctr_set = new uint64_t[NUM_SET];
      per_set_tracker_state = new uint64_t[NUM_SET];
      isUniqRow = new bool[DRAM_CHANNELS * DRAM_RANKS * DRAM_BANKS * DRAM_ROWS];
      memset((void *)CRA_ctr, 0, sizeof(uint64_t) * DRAM_CHANNELS * DRAM_RANKS * DRAM_BANKS * DRAM_ROWS);
      memset((void *)isUniqRow, 0, sizeof(bool) * DRAM_CHANNELS * DRAM_RANKS * DRAM_BANKS * DRAM_ROWS);
      memset((void *)CRA_ctr_set, 0, sizeof(uint64_t) * NUM_SET);
      memset((void *)per_set_tracker_state, 0, sizeof(uint64_t) * NUM_SET);
      cachedCtrs = new std::unordered_set<uint64_t>[NUM_SET];
      rows_per_set = (DRAM_CHANNELS * DRAM_RANKS * DRAM_BANKS * DRAM_ROWS)/NUM_SET;
      if (VWQ_ENABLE) {
        std::cout << "VWQ_ENABLED" << std::endl;
      }
      if (ART_ENABLE) {
        std::cout << "[RH_DEFENSE] ART 0-1-2-8 way policy tracker enabled: state: "
                  << (ART_1B ? "1bit" : "2bit") << " MM: " 
                  << (ART_MM ? "MM_YES" : "MM_NO") << " LITE: " 
                  << (ART_LITE ? "LITE_YES" : "LITE_NO") << std::endl;
      }
      if (HYDRA_ENABLE) {
        std::cout << "[RH_DEFENSE] HYDRA tracker enabled: ROW_GROUP_SIZE "
                  << HYDRA_ROW_GROUP_SIZE << " RCC_SETS " << HYDRA_RCC_SETS << std::endl;
      }
      if (IDEAL_TRACKER) {
        std::cout << "[RH_DEFENSE] IDEAL tracker enabled" << std::endl;
      }
      std::cout << "RH_THRESHOLD " << RH_THRESHOLD << std::endl;
      last_tracker_reset = 0;
    }
  }
};

#endif

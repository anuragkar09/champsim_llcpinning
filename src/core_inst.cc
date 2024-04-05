/***
 * THIS FILE IS AUTOMATICALLY GENERATED
 * Do not edit this file. It will be overwritten when the configure script is run.
 ***/

#include "cache.h"
#include "champsim.h"
#include "dramsim3_wrapper.hpp"
#include "dram_controller.h"
#include "ooo_cpu.h"
#include "ptw.h"
#include "vmem.h"
#include "operable.h"
#include "champsim_constants.h"
#include <array>
#include <vector>
VirtualMemory vmem(68719476736, 1 << 12, 5, 22222222, 200);

DRAMSim3_DRAM DRAM(1.6666666666666667, "/data/anurag/llc_pinning/anish/champsim/dramsim3_configs/DDR5_64GB_4ch_4800.ini", "./");
CACHE LLC("LLC", 1.0, 6, 16384, 16, 256, 256, 256, 1024, 29, 1, 4, 4, LOG2_BLOCK_SIZE, 0, 0, 0, 5, &DRAM, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDhawkeye);
CACHE cpu0_L2C("cpu0_L2C", 1.0, 5, 1024, 8, 32, 32, 16, 64, 9, 1, 2, 2, LOG2_BLOCK_SIZE, 0, 0, 0, 5, &LLC, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu1_L2C("cpu1_L2C", 1.0, 5, 1024, 8, 32, 32, 16, 64, 9, 1, 2, 2, LOG2_BLOCK_SIZE, 0, 0, 0, 5, &LLC, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu2_L2C("cpu2_L2C", 1.0, 5, 1024, 8, 32, 32, 16, 64, 9, 1, 2, 2, LOG2_BLOCK_SIZE, 0, 0, 0, 5, &LLC, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu3_L2C("cpu3_L2C", 1.0, 5, 1024, 8, 32, 32, 16, 64, 9, 1, 2, 2, LOG2_BLOCK_SIZE, 0, 0, 0, 5, &LLC, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu4_L2C("cpu4_L2C", 1.0, 5, 1024, 8, 32, 32, 16, 64, 9, 1, 2, 2, LOG2_BLOCK_SIZE, 0, 0, 0, 5, &LLC, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu5_L2C("cpu5_L2C", 1.0, 5, 1024, 8, 32, 32, 16, 64, 9, 1, 2, 2, LOG2_BLOCK_SIZE, 0, 0, 0, 5, &LLC, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu6_L2C("cpu6_L2C", 1.0, 5, 1024, 8, 32, 32, 16, 64, 9, 1, 2, 2, LOG2_BLOCK_SIZE, 0, 0, 0, 5, &LLC, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu7_L2C("cpu7_L2C", 1.0, 5, 1024, 8, 32, 32, 16, 64, 9, 1, 2, 2, LOG2_BLOCK_SIZE, 0, 0, 0, 5, &LLC, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu0_L1D("cpu0_L1D", 1.0, 4, 64, 8, 64, 64, 8, 16, 4, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 0, 5, &cpu0_L2C, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu1_L1D("cpu1_L1D", 1.0, 4, 64, 8, 64, 64, 8, 16, 4, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 0, 5, &cpu1_L2C, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu2_L1D("cpu2_L1D", 1.0, 4, 64, 8, 64, 64, 8, 16, 4, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 0, 5, &cpu2_L2C, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu3_L1D("cpu3_L1D", 1.0, 4, 64, 8, 64, 64, 8, 16, 4, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 0, 5, &cpu3_L2C, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu4_L1D("cpu4_L1D", 1.0, 4, 64, 8, 64, 64, 8, 16, 4, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 0, 5, &cpu4_L2C, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu5_L1D("cpu5_L1D", 1.0, 4, 64, 8, 64, 64, 8, 16, 4, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 0, 5, &cpu5_L2C, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu6_L1D("cpu6_L1D", 1.0, 4, 64, 8, 64, 64, 8, 16, 4, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 0, 5, &cpu6_L2C, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu7_L1D("cpu7_L1D", 1.0, 4, 64, 8, 64, 64, 8, 16, 4, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 0, 5, &cpu7_L2C, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
PageTableWalker cpu0_PTW("cpu0_PTW", 0, 3, 1, 2, 1, 4, 2, 4, 4, 8, 16, 16, 2, 2, 0, &cpu0_L1D);
PageTableWalker cpu1_PTW("cpu1_PTW", 1, 3, 1, 2, 1, 4, 2, 4, 4, 8, 16, 16, 2, 2, 0, &cpu1_L1D);
PageTableWalker cpu2_PTW("cpu2_PTW", 2, 3, 1, 2, 1, 4, 2, 4, 4, 8, 16, 16, 2, 2, 0, &cpu2_L1D);
PageTableWalker cpu3_PTW("cpu3_PTW", 3, 3, 1, 2, 1, 4, 2, 4, 4, 8, 16, 16, 2, 2, 0, &cpu3_L1D);
PageTableWalker cpu4_PTW("cpu4_PTW", 4, 3, 1, 2, 1, 4, 2, 4, 4, 8, 16, 16, 2, 2, 0, &cpu4_L1D);
PageTableWalker cpu5_PTW("cpu5_PTW", 5, 3, 1, 2, 1, 4, 2, 4, 4, 8, 16, 16, 2, 2, 0, &cpu5_L1D);
PageTableWalker cpu6_PTW("cpu6_PTW", 6, 3, 1, 2, 1, 4, 2, 4, 4, 8, 16, 16, 2, 2, 0, &cpu6_L1D);
PageTableWalker cpu7_PTW("cpu7_PTW", 7, 3, 1, 2, 1, 4, 2, 4, 4, 8, 16, 16, 2, 2, 0, &cpu7_L1D);
CACHE cpu0_STLB("cpu0_STLB", 1.0, 2, 128, 12, 32, 32, 0, 64, 7, 1, 1, 1, LOG2_PAGE_SIZE, 0, 0, 0, 5, &cpu0_PTW, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu1_STLB("cpu1_STLB", 1.0, 2, 128, 12, 32, 32, 0, 64, 7, 1, 1, 1, LOG2_PAGE_SIZE, 0, 0, 0, 5, &cpu1_PTW, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu2_STLB("cpu2_STLB", 1.0, 2, 128, 12, 32, 32, 0, 64, 7, 1, 1, 1, LOG2_PAGE_SIZE, 0, 0, 0, 5, &cpu2_PTW, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu3_STLB("cpu3_STLB", 1.0, 2, 128, 12, 32, 32, 0, 64, 7, 1, 1, 1, LOG2_PAGE_SIZE, 0, 0, 0, 5, &cpu3_PTW, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu4_STLB("cpu4_STLB", 1.0, 2, 128, 12, 32, 32, 0, 64, 7, 1, 1, 1, LOG2_PAGE_SIZE, 0, 0, 0, 5, &cpu4_PTW, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu5_STLB("cpu5_STLB", 1.0, 2, 128, 12, 32, 32, 0, 64, 7, 1, 1, 1, LOG2_PAGE_SIZE, 0, 0, 0, 5, &cpu5_PTW, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu6_STLB("cpu6_STLB", 1.0, 2, 128, 12, 32, 32, 0, 64, 7, 1, 1, 1, LOG2_PAGE_SIZE, 0, 0, 0, 5, &cpu6_PTW, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu7_STLB("cpu7_STLB", 1.0, 2, 128, 12, 32, 32, 0, 64, 7, 1, 1, 1, LOG2_PAGE_SIZE, 0, 0, 0, 5, &cpu7_PTW, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu0_L1I("cpu0_L1I", 1.0, 1, 64, 8, 64, 64, 32, 8, 3, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 1, 5, &cpu0_L2C, CACHE::pref_t::CPU_REDIRECT_pprefetcherDno_instr_, CACHE::repl_t::rreplacementDlru);
CACHE cpu0_ITLB("cpu0_ITLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 1, 5, &cpu0_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu0_DTLB("cpu0_DTLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 0, 5, &cpu0_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu1_L1I("cpu1_L1I", 1.0, 1, 64, 8, 64, 64, 32, 8, 3, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 1, 5, &cpu1_L2C, CACHE::pref_t::CPU_REDIRECT_pprefetcherDno_instr_, CACHE::repl_t::rreplacementDlru);
CACHE cpu1_ITLB("cpu1_ITLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 1, 5, &cpu1_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu1_DTLB("cpu1_DTLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 0, 5, &cpu1_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu2_L1I("cpu2_L1I", 1.0, 1, 64, 8, 64, 64, 32, 8, 3, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 1, 5, &cpu2_L2C, CACHE::pref_t::CPU_REDIRECT_pprefetcherDno_instr_, CACHE::repl_t::rreplacementDlru);
CACHE cpu2_ITLB("cpu2_ITLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 1, 5, &cpu2_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu2_DTLB("cpu2_DTLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 0, 5, &cpu2_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu3_L1I("cpu3_L1I", 1.0, 1, 64, 8, 64, 64, 32, 8, 3, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 1, 5, &cpu3_L2C, CACHE::pref_t::CPU_REDIRECT_pprefetcherDno_instr_, CACHE::repl_t::rreplacementDlru);
CACHE cpu3_ITLB("cpu3_ITLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 1, 5, &cpu3_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu3_DTLB("cpu3_DTLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 0, 5, &cpu3_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu4_L1I("cpu4_L1I", 1.0, 1, 64, 8, 64, 64, 32, 8, 3, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 1, 5, &cpu4_L2C, CACHE::pref_t::CPU_REDIRECT_pprefetcherDno_instr_, CACHE::repl_t::rreplacementDlru);
CACHE cpu4_ITLB("cpu4_ITLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 1, 5, &cpu4_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu4_DTLB("cpu4_DTLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 0, 5, &cpu4_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu5_L1I("cpu5_L1I", 1.0, 1, 64, 8, 64, 64, 32, 8, 3, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 1, 5, &cpu5_L2C, CACHE::pref_t::CPU_REDIRECT_pprefetcherDno_instr_, CACHE::repl_t::rreplacementDlru);
CACHE cpu5_ITLB("cpu5_ITLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 1, 5, &cpu5_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu5_DTLB("cpu5_DTLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 0, 5, &cpu5_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu6_L1I("cpu6_L1I", 1.0, 1, 64, 8, 64, 64, 32, 8, 3, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 1, 5, &cpu6_L2C, CACHE::pref_t::CPU_REDIRECT_pprefetcherDno_instr_, CACHE::repl_t::rreplacementDlru);
CACHE cpu6_ITLB("cpu6_ITLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 1, 5, &cpu6_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu6_DTLB("cpu6_DTLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 0, 5, &cpu6_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu7_L1I("cpu7_L1I", 1.0, 1, 64, 8, 64, 64, 32, 8, 3, 1, 3, 2, LOG2_BLOCK_SIZE, 0, 1, 1, 5, &cpu7_L2C, CACHE::pref_t::CPU_REDIRECT_pprefetcherDno_instr_, CACHE::repl_t::rreplacementDlru);
CACHE cpu7_ITLB("cpu7_ITLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 1, 5, &cpu7_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
CACHE cpu7_DTLB("cpu7_DTLB", 1.0, 1, 16, 4, 16, 16, 0, 32, 0, 1, 2, 2, LOG2_PAGE_SIZE, 0, 1, 0, 5, &cpu7_STLB, CACHE::pref_t::pprefetcherDno, CACHE::repl_t::rreplacementDlru);
O3_CPU cpu0(0, 1.0, 32, 8, 16, 64, 32, 32, 352, 128, 72, 6, 6, 6, 128, 4, 2, 2, 5, 1, 1, 1, 0, 0, &cpu0_ITLB, &cpu0_DTLB, &cpu0_L1I, &cpu0_L1D, O3_CPU::bpred_t::bbranchDhashed_perceptron, O3_CPU::btb_t::bbtbDbasic_btb, O3_CPU::ipref_t::pprefetcherDno_instr);
O3_CPU cpu1(1, 1.0, 32, 8, 16, 64, 32, 32, 352, 128, 72, 6, 6, 6, 128, 4, 2, 2, 5, 1, 1, 1, 0, 0, &cpu1_ITLB, &cpu1_DTLB, &cpu1_L1I, &cpu1_L1D, O3_CPU::bpred_t::bbranchDhashed_perceptron, O3_CPU::btb_t::bbtbDbasic_btb, O3_CPU::ipref_t::pprefetcherDno_instr);
O3_CPU cpu2(2, 1.0, 32, 8, 16, 64, 32, 32, 352, 128, 72, 6, 6, 6, 128, 4, 2, 2, 5, 1, 1, 1, 0, 0, &cpu2_ITLB, &cpu2_DTLB, &cpu2_L1I, &cpu2_L1D, O3_CPU::bpred_t::bbranchDhashed_perceptron, O3_CPU::btb_t::bbtbDbasic_btb, O3_CPU::ipref_t::pprefetcherDno_instr);
O3_CPU cpu3(3, 1.0, 32, 8, 16, 64, 32, 32, 352, 128, 72, 6, 6, 6, 128, 4, 2, 2, 5, 1, 1, 1, 0, 0, &cpu3_ITLB, &cpu3_DTLB, &cpu3_L1I, &cpu3_L1D, O3_CPU::bpred_t::bbranchDhashed_perceptron, O3_CPU::btb_t::bbtbDbasic_btb, O3_CPU::ipref_t::pprefetcherDno_instr);
O3_CPU cpu4(4, 1.0, 32, 8, 16, 64, 32, 32, 352, 128, 72, 6, 6, 6, 128, 4, 2, 2, 5, 1, 1, 1, 0, 0, &cpu4_ITLB, &cpu4_DTLB, &cpu4_L1I, &cpu4_L1D, O3_CPU::bpred_t::bbranchDhashed_perceptron, O3_CPU::btb_t::bbtbDbasic_btb, O3_CPU::ipref_t::pprefetcherDno_instr);
O3_CPU cpu5(5, 1.0, 32, 8, 16, 64, 32, 32, 352, 128, 72, 6, 6, 6, 128, 4, 2, 2, 5, 1, 1, 1, 0, 0, &cpu5_ITLB, &cpu5_DTLB, &cpu5_L1I, &cpu5_L1D, O3_CPU::bpred_t::bbranchDhashed_perceptron, O3_CPU::btb_t::bbtbDbasic_btb, O3_CPU::ipref_t::pprefetcherDno_instr);
O3_CPU cpu6(6, 1.0, 32, 8, 16, 64, 32, 32, 352, 128, 72, 6, 6, 6, 128, 4, 2, 2, 5, 1, 1, 1, 0, 0, &cpu6_ITLB, &cpu6_DTLB, &cpu6_L1I, &cpu6_L1D, O3_CPU::bpred_t::bbranchDhashed_perceptron, O3_CPU::btb_t::bbtbDbasic_btb, O3_CPU::ipref_t::pprefetcherDno_instr);
O3_CPU cpu7(7, 1.0, 32, 8, 16, 64, 32, 32, 352, 128, 72, 6, 6, 6, 128, 4, 2, 2, 5, 1, 1, 1, 0, 0, &cpu7_ITLB, &cpu7_DTLB, &cpu7_L1I, &cpu7_L1D, O3_CPU::bpred_t::bbranchDhashed_perceptron, O3_CPU::btb_t::bbtbDbasic_btb, O3_CPU::ipref_t::pprefetcherDno_instr);
std::array<O3_CPU*, NUM_CPUS> ooo_cpu {
&cpu0, &cpu1, &cpu2, &cpu3, &cpu4, &cpu5, &cpu6, &cpu7
};
std::array<CACHE*, NUM_CACHES> caches {
&LLC, &cpu0_L2C, &cpu1_L2C, &cpu2_L2C, &cpu3_L2C, &cpu4_L2C, &cpu5_L2C, &cpu6_L2C, &cpu7_L2C, &cpu0_L1D, &cpu1_L1D, &cpu2_L1D, &cpu3_L1D, &cpu4_L1D, &cpu5_L1D, &cpu6_L1D, &cpu7_L1D, &cpu0_STLB, &cpu1_STLB, &cpu2_STLB, &cpu3_STLB, &cpu4_STLB, &cpu5_STLB, &cpu6_STLB, &cpu7_STLB, &cpu0_L1I, &cpu0_ITLB, &cpu0_DTLB, &cpu1_L1I, &cpu1_ITLB, &cpu1_DTLB, &cpu2_L1I, &cpu2_ITLB, &cpu2_DTLB, &cpu3_L1I, &cpu3_ITLB, &cpu3_DTLB, &cpu4_L1I, &cpu4_ITLB, &cpu4_DTLB, &cpu5_L1I, &cpu5_ITLB, &cpu5_DTLB, &cpu6_L1I, &cpu6_ITLB, &cpu6_DTLB, &cpu7_L1I, &cpu7_ITLB, &cpu7_DTLB
};
std::array<champsim::operable*, NUM_OPERABLES> operables {
&cpu0, &cpu1, &cpu2, &cpu3, &cpu4, &cpu5, &cpu6, &cpu7, &LLC, &cpu0_L2C, &cpu1_L2C, &cpu2_L2C, &cpu3_L2C, &cpu4_L2C, &cpu5_L2C, &cpu6_L2C, &cpu7_L2C, &cpu0_L1D, &cpu1_L1D, &cpu2_L1D, &cpu3_L1D, &cpu4_L1D, &cpu5_L1D, &cpu6_L1D, &cpu7_L1D, &cpu0_PTW, &cpu1_PTW, &cpu2_PTW, &cpu3_PTW, &cpu4_PTW, &cpu5_PTW, &cpu6_PTW, &cpu7_PTW, &cpu0_STLB, &cpu1_STLB, &cpu2_STLB, &cpu3_STLB, &cpu4_STLB, &cpu5_STLB, &cpu6_STLB, &cpu7_STLB, &cpu0_L1I, &cpu0_ITLB, &cpu0_DTLB, &cpu1_L1I, &cpu1_ITLB, &cpu1_DTLB, &cpu2_L1I, &cpu2_ITLB, &cpu2_DTLB, &cpu3_L1I, &cpu3_ITLB, &cpu3_DTLB, &cpu4_L1I, &cpu4_ITLB, &cpu4_DTLB, &cpu5_L1I, &cpu5_ITLB, &cpu5_DTLB, &cpu6_L1I, &cpu6_ITLB, &cpu6_DTLB, &cpu7_L1I, &cpu7_ITLB, &cpu7_DTLB, &DRAM
};

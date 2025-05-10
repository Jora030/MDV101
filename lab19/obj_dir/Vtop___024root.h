// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(done,0,0);
    CData/*1:0*/ top__DOT__compare_result;
    CData/*7:0*/ top__DOT__CPU__DOT__addr;
    CData/*3:0*/ top__DOT__CPU__DOT__counter;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(result,15,0);
    SData/*15:0*/ top__DOT__instruction;
    SData/*15:0*/ top__DOT__FETCH__DOT__pc;
    SData/*15:0*/ top__DOT__CPU__DOT__alu_out;
    SData/*15:0*/ __Vdly__top__DOT__FETCH__DOT__pc;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 65536> top__DOT__FETCH__DOT__memory;
    VlUnpacked<SData/*15:0*/, 8> top__DOT__CPU__DOT__regfile;
    VlUnpacked<SData/*15:0*/, 256> top__DOT__CPU__DOT__data_memory;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

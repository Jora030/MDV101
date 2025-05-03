// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vprocessor.h for the primary calling header

#ifndef VERILATED_VPROCESSOR___024ROOT_H_
#define VERILATED_VPROCESSOR___024ROOT_H_  // guard

#include "verilated.h"
class Vprocessor___024unit;


class Vprocessor__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vprocessor___024root final : public VerilatedModule {
  public:
    // CELLS
    Vprocessor___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ processor__DOT__valid;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ processor__DOT__instruction;
    SData/*15:0*/ processor__DOT__alu_result;
    SData/*15:0*/ processor__DOT__counter;
    SData/*15:0*/ __Vdly__processor__DOT__counter;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vprocessor__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vprocessor___024root(Vprocessor__Syms* symsp, const char* v__name);
    ~Vprocessor___024root();
    VL_UNCOPYABLE(Vprocessor___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

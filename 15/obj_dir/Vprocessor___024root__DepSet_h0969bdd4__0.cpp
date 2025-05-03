// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprocessor.h for the primary calling header

#include "Vprocessor__pch.h"
#include "Vprocessor__Syms.h"
#include "Vprocessor___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprocessor___024root___dump_triggers__act(Vprocessor___024root* vlSelf);
#endif  // VL_DEBUG

void Vprocessor___024root___eval_triggers__act(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((IData)(vlSelf->reset) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__reset__0)))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vprocessor___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vprocessor___024unit____Vdpiimwrap_bitty_check_TOP____024unit(IData/*31:0*/ instruction, IData/*31:0*/ hardware_result);

VL_INLINE_OPT void Vprocessor___024root___nba_sequent__TOP__1(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSelf->processor__DOT__valid) {
        Vprocessor___024unit____Vdpiimwrap_bitty_check_TOP____024unit(vlSelf->processor__DOT__instruction, (IData)(vlSelf->processor__DOT__alu_result));
    }
}

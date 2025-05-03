// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprocessor.h for the primary calling header

#include "Vprocessor__pch.h"
#include "Vprocessor___024root.h"

VL_ATTR_COLD void Vprocessor___024root___eval_static(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vprocessor___024root___eval_initial(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
}

VL_ATTR_COLD void Vprocessor___024root___eval_final(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vprocessor___024root___eval_settle(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprocessor___024root___dump_triggers__act(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprocessor___024root___dump_triggers__nba(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vprocessor___024root___ctor_var_reset(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->processor__DOT__instruction = VL_RAND_RESET_I(16);
    vlSelf->processor__DOT__alu_result = VL_RAND_RESET_I(16);
    vlSelf->processor__DOT__valid = VL_RAND_RESET_I(1);
    vlSelf->processor__DOT__counter = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__processor__DOT__counter = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
}

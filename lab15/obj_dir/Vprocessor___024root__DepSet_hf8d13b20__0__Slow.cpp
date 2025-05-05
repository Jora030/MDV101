// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprocessor.h for the primary calling header

#include "Vprocessor__pch.h"
#include "Vprocessor___024root.h"

VL_ATTR_COLD void Vprocessor___024root___eval_static(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_static\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vprocessor___024root___eval_initial(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_initial\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

VL_ATTR_COLD void Vprocessor___024root___eval_final(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_final\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vprocessor___024root___eval_settle(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_settle\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprocessor___024root___dump_triggers__act(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___dump_triggers__act\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprocessor___024root___dump_triggers__nba(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___dump_triggers__nba\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vprocessor___024root___ctor_var_reset(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___ctor_var_reset\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->res = VL_RAND_RESET_I(16);
    vlSelf->processor__DOT__instr = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
}

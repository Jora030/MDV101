// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vprocessor__Syms.h"


void Vprocessor___024root__trace_chg_0_sub_0(Vprocessor___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vprocessor___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root__trace_chg_0\n"); );
    // Init
    Vprocessor___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vprocessor___024root*>(voidSelf);
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vprocessor___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vprocessor___024root__trace_chg_0_sub_0(Vprocessor___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root__trace_chg_0_sub_0\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst));
    bufp->chgSData(oldp+2,(vlSelfRef.res),16);
    bufp->chgSData(oldp+3,(vlSelfRef.processor__DOT__instr),16);
}

void Vprocessor___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root__trace_cleanup\n"); );
    // Init
    Vprocessor___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vprocessor___024root*>(voidSelf);
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}

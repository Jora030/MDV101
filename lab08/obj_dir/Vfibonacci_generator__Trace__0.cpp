// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfibonacci_generator__Syms.h"


void Vfibonacci_generator___024root__trace_chg_0_sub_0(Vfibonacci_generator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfibonacci_generator___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator___024root__trace_chg_0\n"); );
    // Init
    Vfibonacci_generator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfibonacci_generator___024root*>(voidSelf);
    Vfibonacci_generator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfibonacci_generator___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vfibonacci_generator___024root__trace_chg_0_sub_0(Vfibonacci_generator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vfibonacci_generator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->rst));
    bufp->chgBit(oldp+2,(vlSelf->enable));
    bufp->chgIData(oldp+3,(vlSelf->fib_out),32);
    bufp->chgIData(oldp+4,(vlSelf->fibonacci_generator__DOT__fib_prev1),32);
    bufp->chgIData(oldp+5,(vlSelf->fibonacci_generator__DOT__fib_prev2),32);
}

void Vfibonacci_generator___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator___024root__trace_cleanup\n"); );
    // Init
    Vfibonacci_generator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfibonacci_generator___024root*>(voidSelf);
    Vfibonacci_generator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}

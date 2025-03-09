// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vkey_lock_fsm__Syms.h"


VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_init_sub__TOP__0(Vkey_lock_fsm___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"key_input",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+4,0,"locked",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("key_lock_fsm", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"key_input",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+4,0,"locked",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"LOCKED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+8,0,"S1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+9,0,"S2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+10,0,"S3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+11,0,"S4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+12,0,"S5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+13,0,"UNLOCKED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+14,0,"KEY1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+14,0,"KEY2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+15,0,"KEY3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+16,0,"KEY4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+15,0,"KEY5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+17,0,"KEY6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+6,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_init_top(Vkey_lock_fsm___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root__trace_init_top\n"); );
    // Body
    Vkey_lock_fsm___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vkey_lock_fsm___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vkey_lock_fsm___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_register(Vkey_lock_fsm___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vkey_lock_fsm___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vkey_lock_fsm___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vkey_lock_fsm___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vkey_lock_fsm___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_const_0_sub_0(Vkey_lock_fsm___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root__trace_const_0\n"); );
    // Init
    Vkey_lock_fsm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkey_lock_fsm___024root*>(voidSelf);
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vkey_lock_fsm___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_const_0_sub_0(Vkey_lock_fsm___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+7,(0U),3);
    bufp->fullCData(oldp+8,(1U),3);
    bufp->fullCData(oldp+9,(2U),3);
    bufp->fullCData(oldp+10,(3U),3);
    bufp->fullCData(oldp+11,(4U),3);
    bufp->fullCData(oldp+12,(5U),3);
    bufp->fullCData(oldp+13,(6U),3);
    bufp->fullCData(oldp+14,(3U),4);
    bufp->fullCData(oldp+15,(5U),4);
    bufp->fullCData(oldp+16,(2U),4);
    bufp->fullCData(oldp+17,(6U),4);
}

VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_full_0_sub_0(Vkey_lock_fsm___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root__trace_full_0\n"); );
    // Init
    Vkey_lock_fsm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkey_lock_fsm___024root*>(voidSelf);
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vkey_lock_fsm___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_full_0_sub_0(Vkey_lock_fsm___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullBit(oldp+2,(vlSelf->reset));
    bufp->fullCData(oldp+3,(vlSelf->key_input),4);
    bufp->fullBit(oldp+4,(vlSelf->locked));
    bufp->fullCData(oldp+5,(vlSelf->key_lock_fsm__DOT__current_state),3);
    bufp->fullCData(oldp+6,(vlSelf->key_lock_fsm__DOT__next_state),3);
}

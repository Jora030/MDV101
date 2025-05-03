// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vprocessor__pch.h"

//============================================================
// Constructors

Vprocessor::Vprocessor(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vprocessor__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vprocessor::Vprocessor(const char* _vcname__)
    : Vprocessor(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vprocessor::~Vprocessor() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vprocessor___024root___eval_debug_assertions(Vprocessor___024root* vlSelf);
#endif  // VL_DEBUG
void Vprocessor___024root___eval_static(Vprocessor___024root* vlSelf);
void Vprocessor___024root___eval_initial(Vprocessor___024root* vlSelf);
void Vprocessor___024root___eval_settle(Vprocessor___024root* vlSelf);
void Vprocessor___024root___eval(Vprocessor___024root* vlSelf);

void Vprocessor::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vprocessor::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vprocessor___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vprocessor___024root___eval_static(&(vlSymsp->TOP));
        Vprocessor___024root___eval_initial(&(vlSymsp->TOP));
        Vprocessor___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vprocessor___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vprocessor::eventsPending() { return false; }

uint64_t Vprocessor::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vprocessor::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vprocessor___024root___eval_final(Vprocessor___024root* vlSelf);

VL_ATTR_COLD void Vprocessor::final() {
    Vprocessor___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vprocessor::hierName() const { return vlSymsp->name(); }
const char* Vprocessor::modelName() const { return "Vprocessor"; }
unsigned Vprocessor::threads() const { return 1; }
void Vprocessor::prepareClone() const { contextp()->prepareClone(); }
void Vprocessor::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vprocessor::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vprocessor::trace()' called on model that was Verilated without --trace option");
}

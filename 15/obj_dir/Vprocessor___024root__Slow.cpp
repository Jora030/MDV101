// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprocessor.h for the primary calling header

#include "Vprocessor__pch.h"
#include "Vprocessor__Syms.h"
#include "Vprocessor___024root.h"

void Vprocessor___024root___ctor_var_reset(Vprocessor___024root* vlSelf);

Vprocessor___024root::Vprocessor___024root(Vprocessor__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vprocessor___024root___ctor_var_reset(this);
}

void Vprocessor___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vprocessor___024root::~Vprocessor___024root() {
}

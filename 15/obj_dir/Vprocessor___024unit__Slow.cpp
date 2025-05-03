// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprocessor.h for the primary calling header

#include "Vprocessor__pch.h"
#include "Vprocessor__Syms.h"
#include "Vprocessor___024unit.h"

void Vprocessor___024unit___ctor_var_reset(Vprocessor___024unit* vlSelf);

Vprocessor___024unit::Vprocessor___024unit(Vprocessor__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vprocessor___024unit___ctor_var_reset(this);
}

void Vprocessor___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vprocessor___024unit::~Vprocessor___024unit() {
}

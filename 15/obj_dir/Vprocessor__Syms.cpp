// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vprocessor__pch.h"
#include "Vprocessor.h"
#include "Vprocessor___024root.h"
#include "Vprocessor___024unit.h"

// FUNCTIONS
Vprocessor__Syms::~Vprocessor__Syms()
{
}

Vprocessor__Syms::Vprocessor__Syms(VerilatedContext* contextp, const char* namep, Vprocessor* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP____024unit{this, Verilated::catName(namep, "$unit")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT____024unit = &TOP____024unit;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
    }
}

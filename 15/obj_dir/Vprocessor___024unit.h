// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vprocessor.h for the primary calling header

#ifndef VERILATED_VPROCESSOR___024UNIT_H_
#define VERILATED_VPROCESSOR___024UNIT_H_  // guard

#include "verilated.h"


class Vprocessor__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vprocessor___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vprocessor__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vprocessor___024unit(Vprocessor__Syms* symsp, const char* v__name);
    ~Vprocessor___024unit();
    VL_UNCOPYABLE(Vprocessor___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

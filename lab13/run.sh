#!/bin/bash
echo "Compiling..."
iverilog -o processor_tb processor_tb.v alu.v register_file.v control_unit.v datapath.v processor.v
if [ $? -eq 0 ]; then
    echo "Running simulation..."
    vvp processor_tb
else
    echo "Compilation failed."
fi

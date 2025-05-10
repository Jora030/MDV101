module top (
    input logic clk,
    input logic reset,
    output logic [15:0] result,
    output logic done
);

    logic [15:0] instruction;

    fetch_unit FETCH (
        .clk(clk),
        .reset(reset),
        .done(done),
        .instruction(instruction)
    );

    bitty_core CPU (
        .clk(clk),
        .reset(reset),
        .instruction(instruction),
        .result(result),
        .done(done)
    );

endmodule

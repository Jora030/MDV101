module top (
    input logic clk,
    input logic reset,
    output logic [15:0] result,
    output logic done
);

    logic [15:0] instruction;
    logic [1:0] compare_result;

    fetch_unit FETCH (
        .clk(clk),
        .reset(reset),
        .done(done),
        .compare_result(compare_result),
        .instruction(instruction)
    );

    bitty_core CPU (
        .clk(clk),
        .reset(reset),
        .instruction(instruction),
        .result(result),
        .done(done),
        .compare_result(compare_result)
    );

endmodule

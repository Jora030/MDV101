module fetch_unit (
    input logic clk,
    input logic reset,
    input logic done,
    output logic [15:0] instruction
);

    logic [15:0] pc;

    program_counter PC (
        .clk(clk),
        .reset(reset),
        .enable(done),
        .pc(pc)
    );

    instruction_memory IM (
        .clk(clk),
        .addr(pc),
        .data(instruction)
    );

endmodule

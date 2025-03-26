
module bitty_core (
    input wire clk,
    input wire reset,
    output wire [15:0] result,
    output wire [3:0] state
);

    wire [2:0] alu_op;
    wire [15:0] reg_out;
    wire [15:0] alu_out;

    reg16 reg1 (
        .clk(clk),
        .enable(1'b1),
        .d(alu_out),
        .q(reg_out)
    );

    controller ctrl (
        .clk(clk),
        .reset(reset),
        .alu_op(alu_op),
        .state(state)
    );

    alu alu1 (
        .op(alu_op),
        .a(reg_out),
        .b(16'h0001),
        .result(alu_out)
    );

    assign result = alu_out;

endmodule

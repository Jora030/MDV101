
module bitty_core (
    input wire clk,
    input wire reset,
    output wire [15:0] result
);

    wire [15:0] reg_out;
    wire [15:0] alu_out;
    wire [3:0] alu_op;
    wire [1:0] shift_op;
    wire [15:0] shifted;

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
        .shift_op(shift_op),
        .state()
    );

    alu alu1 (
        .op(alu_op),
        .a(reg_out),
        .b(16'h0001),
        .result(alu_out)
    );

    shifter sh (
        .op(shift_op),
        .data_in(alu_out),
        .data_out(shifted)
    );

    assign result = shifted;

endmodule

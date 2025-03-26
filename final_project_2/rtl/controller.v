
module controller (
    input clk,
    input reset,
    output reg [2:0] alu_op,
    output reg [3:0] state
);
    localparam S0 = 4'd0, S1 = 4'd1, S2 = 4'd2, S3 = 4'd3,
               S4 = 4'd4, S5 = 4'd5, S6 = 4'd6, S7 = 4'd7;

    always @(posedge clk or posedge reset) begin
        if (reset)
            state <= S0;
        else
            state <= state + 1;
    end

    always @(*) begin
        case (state)
            S0: alu_op = 3'b000; // add
            S1: alu_op = 3'b001; // sub
            S2: alu_op = 3'b010; // and
            S3: alu_op = 3'b011; // or
            S4: alu_op = 3'b100; // xor
            S5: alu_op = 3'b101; // shl
            S6: alu_op = 3'b110; // shr
            S7: alu_op = 3'b111; // cmp
            default: alu_op = 3'b000;
        endcase
    end
endmodule


module alu (
    input  [2:0] op,
    input  [15:0] a, b,
    output reg [15:0] result
);
    always @(*) begin
        case (op)
            3'b000: result = a + b;
            3'b001: result = a - b;
            3'b010: result = a & b;
            3'b011: result = a | b;
            3'b100: result = a ^ b;
            3'b101: result = a << 1;
            3'b110: result = a >> 1;
            3'b111: begin
                if (a == b)      result = 16'd0;
                else if (a > b)  result = 16'd1;
                else             result = -16'd1;
            end
            default: result = 16'hDEAD;
        endcase
    end
endmodule

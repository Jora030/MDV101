
module alu (
    input  [3:0] op,
    input  [15:0] a, b,
    output reg [15:0] result
);
    always @(*) begin
        case (op)
            4'h0: result = a + b;
            4'h1: result = a - b;
            4'h2: result = a & b;
            4'h3: result = a | b;
            4'h4: result = a ^ b;
            4'h5: result = ~a;
            4'h6: result = a << 1;
            4'h7: result = a >> 1;
            default: result = 16'hDEAD;
        endcase
    end
endmodule

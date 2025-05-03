module alu (
    input [15:0] a,
    input [15:0] b,
    input [2:0] alu_sel,
    output reg [15:0] alu_out
);

always @(*) begin
    case (alu_sel)
        3'b000: alu_out = a + b;   
        3'b001: alu_out = a - b;   
        3'b010: alu_out = a & b;  
        3'b011: alu_out = a | b;  
        3'b100: alu_out = a ^ b;  
        3'b101: alu_out = a << b;
        3'b110: alu_out = a >> b;
        3'b111: alu_out = (a == b) ? 16'b1 : 16'b0;
        default: alu_out = 16'b0;
    endcase
end

endmodule


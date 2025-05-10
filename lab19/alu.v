module alu (
    input  logic [15:0] a,
    input  logic [2:0] opcode,
    output logic [15:0] result
);

    always_comb begin
        case (opcode)
            3'b000: result = a + 1;
            3'b001: result = a - 1;
            3'b010: result = a ^ 16'hFFFF;
            3'b011: result = a & 16'h0FFF;
            3'b100: result = a << 1;
            3'b101: result = a >> 1;
            3'b110: result = a | 16'h00FF;
            3'b111: result = 16'h0000;
            default: result = a;
        endcase
    end

endmodule

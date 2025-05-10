module alu (
    input logic [15:0] instruction,
    input logic [15:0] reg_in,
    output logic [15:0] reg_out
);

    logic [2:0] opcode;

    assign opcode = instruction[2:0];

    always_comb begin
        case (opcode)
            3'b000: reg_out = reg_in + 1;
            3'b001: reg_out = reg_in - 1;
            3'b010: reg_out = reg_in ^ 16'hFFFF;
            3'b011: reg_out = reg_in & 16'h0FFF;
            3'b100: reg_out = reg_in << 1;
            3'b101: reg_out = reg_in >> 1;
            3'b110: reg_out = reg_in | 16'h00FF;
            3'b111: reg_out = 16'h0000;
            default: reg_out = reg_in;
        endcase
    end

endmodule

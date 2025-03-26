
module shifter (
    input  [1:0] op,
    input  [15:0] data_in,
    output reg [15:0] data_out
);
    always @(*) begin
        case (op)
            2'b00: data_out = data_in << 1;
            2'b01: data_out = data_in >> 1;
            2'b10: data_out = $signed(data_in) >>> 1;
            default: data_out = 16'hBEEF;
        endcase
    end
endmodule


module mux (
    input wire [15:0] in [9:0],
    input wire [3:0] sel,
    output reg [15:0] out
);
    always @(*) begin
        case (sel)
            4'd0: out = in[0];
            4'd1: out = in[1];
            4'd2: out = in[2];
            4'd3: out = in[3];
            4'd4: out = in[4];
            4'd5: out = in[5];
            4'd6: out = in[6];
            4'd7: out = in[7];
            4'd8: out = in[8];
            4'd9: out = in[9];
            default: out = 16'h0000;
        endcase
    end
endmodule

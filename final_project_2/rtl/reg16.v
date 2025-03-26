
module reg16 (
    input wire clk,
    input wire enable,
    input wire [15:0] d,
    output reg [15:0] q
);
    always @(posedge clk) begin
        if (enable)
            q <= d;
    end
endmodule

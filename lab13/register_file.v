module register_file (
    input clk,
    input we,
    input [2:0] rx,
    input [2:0] ry,
    input [15:0] write_data,
    output [15:0] reg_x,
    output [15:0] reg_y
);

reg [15:0] regs [0:7];

assign reg_x = regs[rx];
assign reg_y = regs[ry];

always @(posedge clk) begin
    if (we)
        regs[rx] <= write_data;
end

endmodule


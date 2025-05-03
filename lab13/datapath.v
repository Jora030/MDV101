module datapath (
    input clk,
    input [15:0] instruction,
    output [15:0] r1, r2, r3
);

wire [2:0] rx, ry, alu_sel;
wire [7:0] immediate;
wire [1:0] format;
wire mux_sel;
wire [15:0] alu_in_b;
wire [15:0] reg_x, reg_y;
wire [15:0] alu_out;

assign rx = instruction[15:13];
assign immediate = instruction[12:5];
assign alu_sel = instruction[4:2];
assign format = instruction[1:0];
assign ry = instruction[12:10];

control_unit cu (.format(format), .mux_sel(mux_sel));
register_file rf (.clk(clk), .we(1'b1), .rx(rx), .ry(ry), .write_data(alu_out), .reg_x(reg_x), .reg_y(reg_y));
alu alu0 (.a(reg_x), .b(alu_in_b), .alu_sel(alu_sel), .alu_out(alu_out));

assign alu_in_b = (mux_sel) ? {8'b0, immediate} : reg_y;

assign r1 = rf.regs[1];
assign r2 = rf.regs[2];
assign r3 = rf.regs[3];

endmodule


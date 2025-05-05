module processor (
    input clk
);

reg [15:0] memory [0:31];
reg [7:0] pc;
wire [15:0] r1, r2, r3;

datapath dp (.clk(clk), .instruction(memory[pc]), .r1(r1), .r2(r2), .r3(r3));

initial begin
    $readmemb("program.mem", memory);
    pc = 0;
end

always @(posedge clk) begin
    pc <= pc + 1;
end

endmodule


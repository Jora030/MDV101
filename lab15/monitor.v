module monitor(
    input logic [15:0] instr,
    input logic [15:0] res
);
    initial begin
        $monitor("INSTR: %h  RES: %h", instr, res);
    end
endmodule

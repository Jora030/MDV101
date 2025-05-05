module processor_tb();

reg clk;
processor uut (.clk(clk));

initial begin
    clk = 0;
    forever #5 clk = ~clk;
end

initial begin
    #300 $finish;
end

initial begin
    $monitor("Time=%0d r1=%d r2=%d r3=%d", $time, uut.dp.r1, uut.dp.r2, uut.dp.r3);
end

endmodule


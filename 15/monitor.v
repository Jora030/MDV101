import "DPI-C" function void bitty_check(input int instruction, input int hardware_result);

module monitor(
    input logic clk,
    input logic valid,
    input logic [15:0] instruction,
    input logic [15:0] result
);
    always_ff @(posedge clk) begin
        if (valid) begin
            bitty_check({16'b0, instruction}, {16'b0, result});
        end
    end
endmodule

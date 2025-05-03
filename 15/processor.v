module processor(
    input logic clk,
    input logic reset
);

    logic [15:0] instruction;
    logic [15:0] alu_result;
    logic valid;

    
    logic [15:0] counter;
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            counter <= 0;
            valid <= 0;
        end else begin
            counter <= counter + 1;
            instruction <= counter;
            alu_result <= counter ^ 16'h00FF;
            valid <= 1;
        end
    end

    monitor m0 (
        .clk(clk),
        .valid(valid),
        .instruction(instruction),
        .result(alu_result)
    );

endmodule

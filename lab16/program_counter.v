module program_counter (
    input logic clk,
    input logic reset,
    input logic enable,
    output logic [15:0] pc
);

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            pc <= 16'h0000;
        end else if (enable) begin
            pc <= pc + 1;
        end
    end

endmodule

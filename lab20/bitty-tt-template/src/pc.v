module pc (
    input  logic clk,
    input  logic reset,
    input  logic inc,
    input  logic [15:0] branch_target,
    input  logic take_branch,
    output logic [15:0] pc
);
    always_ff @(posedge clk or posedge reset) begin
        if (reset)
            pc <= 0;
        else if (take_branch)
            pc <= branch_target;
        else if (inc)
            pc <= pc + 1;
    end
endmodule

module fetch_unit (
    input logic clk,
    input logic reset,
    input logic done,
    input logic [1:0] compare_result,
    output logic [15:0] instruction
);

    logic [15:0] pc;
    logic [15:0] next_pc;
    logic [15:0] memory [0:65535];

    initial begin
        $readmemh("prog.hex", memory);
    end

    wire is_branch = (instruction[1:0] == 2'b10);
    wire [1:0] branch_cond = instruction[3:2];
    wire [15:0] branch_target = {instruction[15:4], 4'b0000};

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            pc <= 0;
        end else if (done) begin
            if (is_branch) begin
                if (compare_result == branch_cond)
                    pc <= branch_target;
                else
                    pc <= pc + 1;
            end else begin
                pc <= pc + 1;
            end
        end
    end

    always_ff @(posedge clk) begin
        instruction <= memory[pc];
    end

endmodule

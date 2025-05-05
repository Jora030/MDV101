module processor(
    input logic clk,
    input logic rst,
    output logic [15:0] res
);

    logic [15:0] instr;

    import "DPI-C" function int get_instruction();
    import "DPI-C" function int eval_instruction(input int instr);

    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            res <= 0;
        else begin
            instr <= get_instruction()[15:0];
            res <= eval_instruction({16'b0, instr})[15:0];
        end
    end
endmodule

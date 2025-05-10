module bitty_core (
    input  logic clk,
    input  logic reset,
    input  logic [15:0] instruction,
    output logic [15:0] result,
    output logic done,
    output logic [1:0] compare_result
);

    logic [15:0] reg_a, reg_b, reg_out;
    logic [2:0] opcode;
    logic [3:0] counter;

    assign opcode = instruction[2:0];

    always_comb begin
        case (opcode)
            3'b000: reg_out = reg_a + 1;
            3'b001: reg_out = reg_a - 1;
            3'b010: reg_out = reg_a ^ 16'hFFFF;
            3'b011: reg_out = reg_a & 16'h0FFF;
            3'b100: reg_out = reg_a << 1;
            3'b101: reg_out = reg_a >> 1;
            3'b110: reg_out = reg_a | 16'h00FF;
            3'b111: reg_out = 16'h0000;
            default: reg_out = reg_a;
        endcase
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            reg_a <= 0;
            reg_b <= 0;
            result <= 0;
            counter <= 0;
            done <= 0;
            compare_result <= 0;
        end else begin
            if (counter == 3) begin
                reg_a <= reg_out;
                result <= reg_out;
                done <= 1;

                if (reg_a == reg_b) compare_result <= 2'b00;
                else if (reg_a > reg_b) compare_result <= 2'b01;
                else compare_result <= 2'b10;

                counter <= 0;
            end else begin
                done <= 0;
                counter <= counter + 1;
            end
        end
    end

endmodule

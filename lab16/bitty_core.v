module bitty_core (
    input logic clk,
    input logic reset,
    input logic [15:0] instruction,
    output logic [15:0] result,
    output logic done
);

    logic [15:0] reg_out;
    logic [15:0] reg_in;
    logic [2:0] opcode;
    logic [3:0] counter;

    assign opcode = instruction[2:0];

    // Примитивная ALU на основе opcode
    always_comb begin
        case (opcode)
            3'b000: reg_in = reg_out + 1;
            3'b001: reg_in = reg_out - 1;
            3'b010: reg_in = reg_out ^ 16'hFFFF;
            3'b011: reg_in = reg_out & 16'h0FFF;
            3'b100: reg_in = reg_out << 1;
            3'b101: reg_in = reg_out >> 1;
            3'b110: reg_in = reg_out | 16'h00FF;
            3'b111: reg_in = 16'h0000;
            default: reg_in = reg_out;
        endcase
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            reg_out <= 0;
            counter <= 0;
            done <= 0;
        end else begin
            if (counter == 3) begin
                reg_out <= reg_in;
                done <= 1;
                counter <= 0;
            end else begin
                done <= 0;
                counter <= counter + 1;
            end
        end
    end

    assign result = reg_out;

endmodule

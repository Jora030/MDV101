module bitty_core (
    input  logic clk,
    input  logic reset,
    input  logic [15:0] instruction,
    output logic [15:0] result,
    output logic done,
    output logic [1:0] compare_result
);

    logic [15:0] regfile [0:7];  // 8 регистров общего назначения
    logic [15:0] data_memory [0:255];

    logic [15:0] alu_out;
    logic [15:0] mem_out;
    logic [2:0] rx, ry, opcode;
    logic [7:0] addr;
    logic [3:0] counter;
    logic is_branch, is_mem;
    logic mem_is_load, mem_is_store;

    assign rx = instruction[15:13];
    assign ry = instruction[12:10];
    assign opcode = instruction[2:0];
    assign addr = regfile[ry][7:0];

    assign is_branch = (instruction[1:0] == 2'b10);
    assign is_mem    = (instruction[1:0] == 2'b11);
    assign mem_is_load  = is_mem && (instruction[2] == 1'b0);
    assign mem_is_store = is_mem && (instruction[2] == 1'b1);

    always_comb begin
        case (opcode)
            3'b000: alu_out = regfile[rx] + 1;
            3'b001: alu_out = regfile[rx] - 1;
            3'b010: alu_out = regfile[rx] ^ 16'hFFFF;
            3'b011: alu_out = regfile[rx] & 16'h0FFF;
            3'b100: alu_out = regfile[rx] << 1;
            3'b101: alu_out = regfile[rx] >> 1;
            3'b110: alu_out = regfile[rx] | 16'h00FF;
            3'b111: alu_out = 0;
            default: alu_out = regfile[rx];
        endcase
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            result <= 0;
            done <= 0;
            counter <= 0;
            compare_result <= 0;
        end else begin
            if (counter == 3) begin
                done <= 1;
                counter <= 0;

                if (is_mem) begin
                    if (mem_is_load) begin
                        regfile[rx] <= data_memory[addr];
                        result <= data_memory[addr];
                    end else if (mem_is_store) begin
                        data_memory[addr] <= regfile[rx];
                        result <= regfile[rx];
                    end
                end else begin
                    regfile[rx] <= alu_out;
                    result <= alu_out;
                    // обновление compare_result
                    if (regfile[rx] == regfile[ry]) compare_result <= 0;
                    else if (regfile[rx] > regfile[ry]) compare_result <= 1;
                    else compare_result <= 2;
                end

            end else begin
                done <= 0;
                counter <= counter + 1;
            end
        end
    end

endmodule

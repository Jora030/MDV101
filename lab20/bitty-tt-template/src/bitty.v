module bitty (
    input  logic clk,
    input  logic reset,
    input  logic run,
    input  logic [15:0] d_instr,
    output logic [15:0] d_out,
    output logic done
);

    typedef enum logic [1:0] {
        IDLE,
        FETCH,
        EXECUTE,
        WRITEBACK
    } state_t;

    state_t state, next_state;

    logic [15:0] instr;
    logic [15:0] regfile [0:7];
    logic [15:0] pc;
    logic [15:0] result;

    assign d_out = result;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            pc <= 0;
        end else begin
            state <= next_state;
        end
    end

    always_comb begin
        next_state = state;
        done = 0;
        case (state)
            IDLE: begin
                if (run)
                    next_state = FETCH;
            end
            FETCH: begin
                next_state = EXECUTE;
            end
            EXECUTE: begin
                next_state = WRITEBACK;
            end
            WRITEBACK: begin
                done = 1;
                next_state = FETCH;
            end
        endcase
    end

    logic [2:0] opcode, rx, ry;
    assign opcode = instr[2:0];
    assign rx = instr[15:13];
    assign ry = instr[12:10];

    logic [15:0] alu_result;
    always_comb begin
        case (opcode)
            3'b000: alu_result = regfile[rx] + 1;
            3'b001: alu_result = regfile[rx] - 1;
            3'b010: alu_result = regfile[rx] ^ 16'hFFFF;
            3'b011: alu_result = regfile[rx] & 16'h0FFF;
            3'b100: alu_result = regfile[rx] << 1;
            3'b101: alu_result = regfile[rx] >> 1;
            3'b110: alu_result = regfile[rx] | 16'h00FF;
            3'b111: alu_result = 16'h0000;
            default: alu_result = 16'h0000;
        endcase
    end

    always_ff @(posedge clk) begin
        if (reset) begin
            for (int i = 0; i < 8; i++) regfile[i] <= 0;
            result <= 0;
        end else if (state == FETCH) begin
            instr <= d_instr;
        end else if (state == WRITEBACK) begin
            regfile[rx] <= alu_result;
            result <= alu_result;
            pc <= pc + 1;
        end
    end

endmodule

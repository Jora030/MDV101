module project_final (
    input  logic clk,
    input  logic reset,
    input  logic [7:0] rx_data,
    input  logic rx_done,
    input  logic tx_done,
    output logic [7:0] tx_data,
    output logic tx_en
);

    logic [15:0] instr;
    logic [15:0] result;
    logic done, run;
    logic [3:0] state;

    typedef enum logic [3:0] {
        IDLE,
        LOAD_L,
        LOAD_H,
        RUN_CORE,
        WAIT_DONE,
        SEND_L,
        SEND_H
    } state_t;

    state_t current_state, next_state;
    logic [15:0] instr_reg;
    logic [7:0] low_byte, high_byte;

    bitty core (
        .clk(clk),
        .reset(reset),
        .run(run),
        .d_instr(instr_reg),
        .d_out(result),
        .done(done)
    );

    assign instr = instr_reg;

    always_ff @(posedge clk or posedge reset) begin
        if (reset)
            current_state <= IDLE;
        else
            current_state <= next_state;
    end

    always_comb begin
        next_state = current_state;
        run = 0;
        tx_en = 0;
        case (current_state)
            IDLE: if (rx_done) next_state = LOAD_L;
            LOAD_L: next_state = LOAD_H;
            LOAD_H: next_state = RUN_CORE;
            RUN_CORE: begin
                run = 1;
                next_state = WAIT_DONE;
            end
            WAIT_DONE: if (done) next_state = SEND_L;
            SEND_L: if (tx_done) next_state = SEND_H;
            SEND_H: if (tx_done) next_state = IDLE;
        endcase
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            instr_reg <= 16'h0000;
            {low_byte, high_byte} <= 16'h0000;
        end else begin
            case (current_state)
                LOAD_L: instr_reg[7:0] <= rx_data;
                LOAD_H: instr_reg[15:8] <= rx_data;
                SEND_L: begin
                    tx_data <= result[7:0];
                    tx_en <= 1;
                end
                SEND_H: begin
                    tx_data <= result[15:8];
                    tx_en <= 1;
                end
            endcase
        end
    end

endmodule

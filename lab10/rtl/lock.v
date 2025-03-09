`timescale 1ns / 1ps
module key_lock_fsm (
    input clk,
    input reset,
    input [3:0] key_input, // Ввод одной цифры (4 бита)
    output reg locked // 1 = закрыто, 0 = открыто
);

// Определение состояний
parameter LOCKED = 3'd0, S1 = 3'd1, S2 = 3'd2, S3 = 3'd3, S4 = 3'd4, S5 = 3'd5, UNLOCKED = 3'd6;

// Последовательность пароля
parameter KEY1 = 4'd3, KEY2 = 4'd3, KEY3 = 4'd5, KEY4 = 4'd2, KEY5 = 4'd5, KEY6 = 4'd6;

reg [2:0] current_state, next_state;

// Регистры состояния (последовательная логика)
always @(posedge clk or posedge reset) begin
    if (reset)
        current_state <= LOCKED;
    else
        current_state <= next_state;
end

// Логика переходов состояний (комбинационная логика)
always @(*) begin
    case (current_state)
        LOCKED:   next_state = (key_input == KEY1) ? S1 : LOCKED;
        S1:       next_state = (key_input == KEY2) ? S2 : LOCKED;
        S2:       next_state = (key_input == KEY3) ? S3 : LOCKED;
        S3:       next_state = (key_input == KEY4) ? S4 : LOCKED;
        S4:       next_state = (key_input == KEY5) ? S5 : LOCKED;
        S5:       next_state = (key_input == KEY6) ? UNLOCKED : LOCKED;
        UNLOCKED: next_state = UNLOCKED; // Остаётся открытым
        default:  next_state = LOCKED;
    endcase
end

// Выходная логика (locked = 0 при UNLOCKED)
always @(*) begin
    locked = (current_state == UNLOCKED) ? 0 : 1;
end

// Отладочный вывод
always @(posedge clk) begin
    $display("CLK: %d | Input: %d | Current State: %d | Next State: %d | Locked: %b", 
             $time, key_input, current_state, next_state, locked);
    $fflush();
end



endmodule

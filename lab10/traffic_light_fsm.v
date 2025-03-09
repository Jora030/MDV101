`timescale 1ns / 1ps

module traffic_light_fsm (
    input clk,           // Тактовый сигнал
    input reset,         // Асинхронный сброс
    output reg [2:0] light // Выход (состояние светофора: RED, GREEN, YELLOW)
);

// Кодирование состояний
parameter RED = 2'b00, GREEN = 2'b01, YELLOW = 2'b10;

// Таймерные задержки (число тактов для каждого состояния)
parameter RED_TIME = 5;     
parameter GREEN_TIME = 4;    
parameter YELLOW_TIME = 2;    

reg [1:0] current_state, next_state;
reg [3:0] counter;  // Счётчик тактов

// Регистры состояния и таймера (последовательная логика)
always @(posedge clk or posedge reset) begin
    if (reset) begin
        current_state <= RED;
        counter <= 0;
    end else begin
        if (counter == 0) begin
            current_state <= next_state;
            case (next_state)
                RED: counter <= RED_TIME;
                GREEN: counter <= GREEN_TIME;
                YELLOW: counter <= YELLOW_TIME;
            endcase
        end else begin
            counter <= counter - 1;
        end
    end
end

// Логика переходов состояний (комбинационная логика)
always @(*) begin
    case (current_state)
        RED: next_state = GREEN;
        GREEN: next_state = YELLOW;
        YELLOW: next_state = RED;
        default: next_state = RED;
    endcase
end

// Выходная логика (управление светом)
always @(*) begin
    case (current_state)
        RED: light = 3'b001;    // Красный
        GREEN: light = 3'b010;  // Зелёный
        YELLOW: light = 3'b100; // Жёлтый
        default: light = 3'b001; // По умолчанию красный
    endcase
end

endmodule


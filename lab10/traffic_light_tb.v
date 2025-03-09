`timescale 1ns / 1ps

module traffic_light_tb;
    reg clk;
    reg reset;
    wire [2:0] light;

    // Подключаем FSM
    traffic_light_fsm uut (
        .clk(clk),
        .reset(reset),
        .light(light)
    );

    // Генерация тактового сигнала (50% duty cycle)
    always #5 clk = ~clk;  

    initial begin
        $dumpfile("traffic_light_tb.vcd"); // Создаём файл VCD
        $dumpvars(0, traffic_light_tb);   // Сохраняем все сигналы
        
        clk = 0;
        reset = 1;  // Делаем сброс
        #10 reset = 0; // Через 10 тактов убираем сброс
        
        // Даем симуляции поработать 50 тактов
        #50;

        $finish; // Завершаем симуляцию
    end
endmodule


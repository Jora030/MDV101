`timescale 1ns / 1ps

module alu_tb;
    reg [15:0] A, B;
    reg [1:0] mode, op;
    wire [15:0] alu_out;
    wire compare;

    // Подключаем ALU
    alu_74181 uut (
        .A(A), 
        .B(B), 
        .mode(mode), 
        .op(op), 
        .alu_out(alu_out), 
        .compare(compare)
    );

    initial begin
        $dumpfile("alu_tb.vcd");
        $dumpvars(0, alu_tb);

        // Тест 1: Сложение
        A = 16'h0005; B = 16'h0003; mode = 2'b00; op = 2'b00; #10;
        $display("A = %h, B = %h, Mode = %b, Op = %b, Out = %h, Compare = %b", A, B, mode, op, alu_out, compare);

        // Тест 2: Вычитание
        A = 16'h000A; B = 16'h0004; mode = 2'b00; op = 2'b01; #10;
        $display("A = %h, B = %h, Mode = %b, Op = %b, Out = %h, Compare = %b", A, B, mode, op, alu_out, compare);

        // Тест 3: Побитовое И
        A = 16'h00FF; B = 16'h0F0F; mode = 2'b01; op = 2'b00; #10;
        $display("A = %h, B = %h, Mode = %b, Op = %b, Out = %h, Compare = %b", A, B, mode, op, alu_out, compare);

        // Тест 4: Побитовое ИЛИ
        A = 16'h00FF; B = 16'h0F0F; mode = 2'b01; op = 2'b01; #10;
        $display("A = %h, B = %h, Mode = %b, Op = %b, Out = %h, Compare = %b", A, B, mode, op, alu_out, compare);

        $finish;
    end
endmodule


`timescale 1ns / 1ps

module arithmetic_unit(
    input wire [15:0] A, B,
    input wire [1:0] op,
    output reg [15:0] result
);
    always @(*) begin
        case (op)
            2'b00: result = A + B;  // Сложение
            2'b01: result = A - B;  // Вычитание
            2'b10: result = A * B;  // Умножение
            default: result = 16'b0; // Ошибка
        endcase
    end
endmodule

module logic_unit(
    input wire [15:0] A, B,
    input wire [1:0] op,
    output reg [15:0] result
);
    always @(*) begin
        case (op)
            2'b00: result = A & B;  // AND
            2'b01: result = A | B;  // OR
            2'b10: result = A ^ B;  // XOR
            default: result = ~A;   // NOT (только для A)
        endcase
    end
endmodule

module alu_74181(
    input wire [15:0] A, B,
    input wire [1:0] mode,  // 0 - арифметика, 1 - логика
    input wire [1:0] op,
    output wire [15:0] alu_out,
    output wire compare
);
    wire [15:0] arithmetic_res, logic_res;

    arithmetic_unit arith (
        .A(A), 
        .B(B), 
        .op(op), 
        .result(arithmetic_res)
    );

    logic_unit logic_ (
        .A(A), 
        .B(B), 
        .op(op), 
        .result(logic_res)
    );

    assign alu_out = (mode == 2'b00) ? arithmetic_res : logic_res;
    assign compare = (A == B) ? 1'b1 : 1'b0;
endmodule


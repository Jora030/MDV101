#include "Vand_gate.h"
#include "verilated.h"
#include "verilated_vcd_c.h"  // Подключаем поддержку VCD-трассировки
#include <iostream>

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vand_gate* and_gate = new Vand_gate;

    // Включаем трассировку
    Verilated::traceEverOn(true);
    VerilatedVcdC* vcd_trace = new VerilatedVcdC;
    and_gate->trace(vcd_trace, 99); // 99 уровней иерархии
    vcd_trace->open("and_gate_trace.vcd"); // Открываем VCD-файл

    // Тестовые случаи с трассировкой
    and_gate->a = 0; and_gate->b = 0;
    and_gate->eval();
    vcd_trace->dump(10);  // Запись данных в момент времени 10
    std::cout << "a=0, b=0 -> y=" << (int)and_gate->y << std::endl;

    and_gate->a = 0; and_gate->b = 1;
    and_gate->eval();
    vcd_trace->dump(20);
    std::cout << "a=0, b=1 -> y=" << (int)and_gate->y << std::endl;

    and_gate->a = 1; and_gate->b = 0;
    and_gate->eval();
    vcd_trace->dump(30);
    std::cout << "a=1, b=0 -> y=" << (int)and_gate->y << std::endl;

    and_gate->a = 1; and_gate->b = 1;
    and_gate->eval();
    vcd_trace->dump(40);
    std::cout << "a=1, b=1 -> y=" << (int)and_gate->y << std::endl;

    // Закрываем VCD-файл
    vcd_trace->close();

    delete and_gate;
    delete vcd_trace;
    return 0;
}


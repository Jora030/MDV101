module instruction_memory (
    input logic clk,
    input logic [15:0] addr,
    output logic [15:0] data
);

    logic [15:0] memory [0:65535];

    initial begin
        $display("Loading instruction memory from prog.hex...");
        $readmemh("prog.hex", memory);
    end

    always_ff @(posedge clk) begin
        data <= memory[addr];
    end

endmodule

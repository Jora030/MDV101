module lsu (
    input  logic clk,
    input  logic reset,
    input  logic mem_write,
    input  logic enable,
    input  logic [15:0] addr,
    input  logic [15:0] write_data,
    output logic [15:0] read_data
);

    logic [15:0] mem [0:255];

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            for (int i = 0; i < 256; i++) mem[i] <= 16'h0000;
        end else if (enable && mem_write) begin
            mem[addr[7:0]] <= write_data;
        end
    end

    always_comb begin
        if (enable && !mem_write)
            read_data = mem[addr[7:0]];
        else
            read_data = 16'h0000;
    end

endmodule

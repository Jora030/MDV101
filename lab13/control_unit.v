module control_unit (
    input [1:0] format,
    output reg mux_sel
);

always @(*) begin
    if (format == 2'b01)
        mux_sel = 1'b1; // Immediate
    else
        mux_sel = 1'b0; // Register
end

endmodule


module mux2to1 (
    input  logic sel,
    input  logic [15:0] in0,
    input  logic [15:0] in1,
    output logic [15:0] out
);
    assign out = sel ? in1 : in0;
endmodule

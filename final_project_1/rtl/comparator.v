
module comparator (
    input  [15:0] a,
    input  [15:0] b,
    output        eq,
    output        gt,
    output        lt
);
    assign eq = (a == b);
    assign gt = (a > b);
    assign lt = (a < b);
endmodule

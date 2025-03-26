
module controller (
    input clk,
    input reset,
    output reg [3:0] alu_op,
    output reg [1:0] shift_op,
    output reg [3:0] state
);

    localparam S0 = 4'd0, S1 = 4'd1, S2 = 4'd2, S3 = 4'd3;

    always @(posedge clk or posedge reset) begin
        if (reset)
            state <= S0;
        else begin
            case (state)
                S0: state <= S1;
                S1: state <= S2;
                S2: state <= S3;
                S3: state <= S0;
                default: state <= S0;
            endcase
        end
    end

    always @(*) begin
        case (state)
            S0: begin alu_op = 4'h0; shift_op = 2'b00; end
            S1: begin alu_op = 4'h1; shift_op = 2'b01; end
            S2: begin alu_op = 4'h2; shift_op = 2'b10; end
            S3: begin alu_op = 4'h3; shift_op = 2'b11; end
            default: begin alu_op = 4'hF; shift_op = 2'b11; end
        endcase
    end
endmodule

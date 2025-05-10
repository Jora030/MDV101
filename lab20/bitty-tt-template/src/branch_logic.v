module branch_logic (
    input  logic [15:0] reg_x,
    input  logic [15:0] reg_y,
    input  logic [1:0] branch_type,
    output logic take_branch
);
    always_comb begin
        case (branch_type)
            2'b00: take_branch = (reg_x == reg_y); // BIE
            2'b01: take_branch = (reg_x > reg_y);  // BIG
            2'b10: take_branch = (reg_x < reg_y);  // BIL
            default: take_branch = 1'b0;
        endcase
    end
endmodule

module fibonacci_generator (
    input clk,        
    input rst,       
    input enable,     
    output reg [31:0] fib_out  
);

    reg [31:0] fib_prev1;  
    reg [31:0] fib_prev2; 

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            // Initialize Fibonacci numbers
            fib_prev1 <= 32'd1;  
            fib_prev2 <= 32'd0;  
            fib_out <= 32'd0; 
        end else if (enable) begin
            // Compute next Fibonacci number
            fib_out <= fib_prev1 + fib_prev2;

            // Update previous Fibonacci numbers
            fib_prev2 <= fib_prev1;
            fib_prev1 <= fib_out;
        end
    end

endmodule

# Part 1
For part 1, I used argc and argv to get the input for the 5 values of h. A for loop was used to iterate through each value of h and output all of the results that were asked for using std::cout and std::endl, and escape sequences to make the formatting easy to read.

## Calculations
The calculations are structured by defining variables for each component of the finite difference formula and the center difference formula, and then writing out the whole equation using the predefined variables. Cmath was used in order to access math functions such as sin and cos. The actual value of y' = cos(x) was calculated in order to find the errors of the two approximations using the percent error formula.

> I did not use the template for part 1 but my formatting is similar.

# Part 2
For the second part, I started by using argc and argv to input a value of N. I used the black-box function that was given to us to get randomized values in dynamic arrays float *x, *y, and *z the size of N. Cmath was also used in part 2.

## Iterative Loop
For my iterative loop, I used a while loop that ran while i < N. Before the loop I defined n1 as an array of x[0], y[0], and z[0] as well as n2_max and n2_min which were initially defined as arrays at index 1. I used these values to find l_max and l_min, which were initially both the same since n2_max and n2_min were the same. In order to do the multiplication inside of acos for the formula of l, I created a dot product function that individually multiplied the values of x, y, and z, and took the sum. 

In the loop, n2_new_max and n2_new_min were defined as arrays at index i+1. This value was used to calculate l_new_max and l_new_min. Two if statements evaluated if l_new_max > l_max and l_new_min < l_min and if they were then the original values of n2 and l would be updated to the new ones. If the if statement was not met, nothing would happen and the minimum or maximum values would be kept the same for the next iteration. The counter, i++, was used to increment i by 1 for each iteration. 

This loop allows the current values of n and l to be updated only if they will be smaller (for finding the min) or larger (for finding the max) than the previous value, eventually leading to the correct answer.

## End of code
Once the loop is finished iterating. The min and max values are found and printed using cout and escape sequences. Then, the memory of x, y, and z was deleted to prevent a memory leak.
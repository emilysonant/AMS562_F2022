#include <iostream>
#include <cmath>

int main(int argc, char *argv[]){ 
//defining variables
//defines x
float x = M_PI/4.0f;

for (int i=1; i < 6; i++){
//defines h
std::string h_str = argv[i];
float h = std::stof(h_str);

//part 1 - finite difference method
//approximation of y' = [f(x+h)-f(x)]/h for y = sin(x)

float y_prime = cos(x); //actual y' = cos(x)
float y = sin(x); //f(x)
float y_new = sin(x+h); //f(x+h)

float y_prime_fd = (y_new - y)/h; //approximation for y' using the finite difference method

float percent_error_fd = fabs(((y_prime_fd - y_prime)/y_prime)*100); //percent error between approximation and actual value for finite difference method

//part 1 - center-difference method
//approximation of y' = [f(x+h)-f(x-h)]/2h for y = sin(x)

float y_old = sin(x-h); //f(x-h)

float y_prime_cd = (y_new - y_old)/(2*h); //approximation for y' using the center difference method

float percent_error_cd = fabs(((y_prime_cd - y_prime)/y_prime)*100); //percent error between approximation and actual value for center difference method

//prints results
std::cout << "y' =\t" << y_prime << std::endl;
std::cout << "for h =\t" << h << "\nthe finite difference method approximation is\t" << y_prime_fd << "\nwith a percent error of\t" << percent_error_fd << "\nthe center difference approximation is\t" << y_prime_cd << "\nwith a percent error of\t" << percent_error_cd << "\n" << std::endl;
}

return 0;
}
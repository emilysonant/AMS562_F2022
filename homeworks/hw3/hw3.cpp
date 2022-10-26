#include <iostream>
#include <cmath>

int main()
{ 
//defining variables
//defines x
float x = M_PI/4.0f;

//asks user for h
std::cout << "Please enter the value of h:\t";
std::string h_str;
std::cin >> h_str;
float h = std::stof(h_str);

//returns x and h
std::cout << x << std::endl;
std::cout << h << std::endl;

//part 1 - finite difference method
//approximation of y' = [f(x+h)-f(x)]/h for y = sin(x)

float y_prime = cos(x); //actual y' = cos(x)
float y = sin(x); //f(x)
float y_new = sin(x+h); //f(x+h)

float y_prime_fd = (y_new - y)/h; //approximation for y' using the finite difference method

float percent_error_fd = fabs(((y_prime_fd - y_prime)/y_prime)*100); //percent error between approximation and actual value for finite difference method

//returns y' fd approximation, y' actual, and percent error
std::cout << y_prime << std::endl;
std::cout << y_prime_fd << std::endl;
std::cout << percent_error_fd << std::endl;

//part 1 - center-difference method
//approximation of y' = [f(x+h)-f(x-h)]/2h for y = sin(x)

float y_old = sin(x-h); //f(x-h)

float y_prime_cd = (y_new - y_old)/(2*h); //approximation for y' using the center difference method

float percent_error_cd = fabs(((y_prime_cd - y_prime)/y_prime)*100); //percent error between approximation and actual value for center difference method

//returns y' cd approximation and percent error
std::cout << y_prime_cd << std::endl;
std::cout << percent_error_cd << std::endl;

return 0;
}
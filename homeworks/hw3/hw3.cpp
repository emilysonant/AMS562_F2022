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

//part 1 - finite difference formula
//approximating y' = [f(x+h)-f(x)]/h for y = sin(x)

float y_prime = cos(x); //actual y' = cos(x)
float y = sin(x); //f(x)
float y_new = sin(x+h); //f(x+h)

float y_prime_approx = (y_new - y)/h; //approximation for y'

float percent_error = fabs(((y_prime_approx - y_prime)/y_prime)*100); //percent error between approximation and actual value

// std::cout << "the value of y' is actually:\t" << std::endl;

//returns y' actual, expected, and percent error
std::cout << y_prime << std::endl;
std::cout << y_prime_approx << std::endl;
std::cout << percent_error << std::endl;

return 0;
}
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

return 0;
}
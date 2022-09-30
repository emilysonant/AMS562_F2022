#include <iostream>

int main() {
    //asks for title, first name, and last name
    std::cout << "Please enter your title, first name, and last name";
    std::string title, fname, lname;
    std::cin >> title >> fname >> lname;

    //asks for dob
    std::cout << "Please enter your date of birth (mm/dd/yyyy)";
    std::string dob;
    std::cin >> dob;

    //asks for bio
    std::string bio;
    std::cout << "Please enter a bio about yourself \n";
    std::getline(std::cin, bio);

    
}
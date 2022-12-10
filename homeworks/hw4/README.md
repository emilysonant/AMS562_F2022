# The array.cpp file
In order to do homework 4, the first step was to create all of the functions in array.cpp. Each function defined in array.hpp was written in array.cpp.

## Constructors
The first functions are constructors which are used to initialize the object. 

The default constructor is made which defines array with no inputs as size = 0 and data = 0. 

The copy constructor will initialize an array as a copy of another array given as the input. 

Then, the initialization for an array for a defined size, n, and data, v. The data points were multiplied by the counter i so that each element of the array has a different value making it easier to test the functions.

## Destructor
The destructor is created to destroy the arrays initialized in constructors.

## Member Functions
Member functions are the functions inside the class, so they have access to the variables created in the class (ex. _size and _data). Functions were made for all of the defined ones in array.hpp. For example, there is a function for resizing, returning the sum and difference of arrays, returning the dot product, etc.

## Free Functions
The two free functions are used to define the operators + and - to add and subtract two arrays.

# The main.cpp file
The main.cpp file is used to test all of the functions in array.cpp. There are tests written for each function, except for a few that are tested in other functions such as the function for printing. The tests are all printed so that the values can be checked.
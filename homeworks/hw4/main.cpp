#include <iostream>
#include "array.hpp"

int main() {
    Array test_array(3, 7);
    Array test_array_2(3, 8);

    //test default constructor
    Array arr_1;
    std::cout << " size: " << arr_1.size();

    //test copy constructor
    Array arr_2(test_array);
    std::cout << "\n copy constructor: ";
    arr_2.print();

    //test length of array
    unsigned size = test_array.size();
    std::cout << "\n length of array: " << size;

    //test data pointer of array
    double* pointer = test_array.data();
    std::cout << "\n data pointer: " << pointer;

    //test read-only pointer of array
    const double* ro_pointer = test_array.data();
    std::cout << "\n read-only pointer: " << ro_pointer;

    //test copying array
    Array arr_3(test_array.size());
    arr_3.copy(test_array);
    std::cout << "\n original: ";
    test_array.print();
    std::cout << "\t copy: ";
    arr_3.print();

    //test reference entry "index"
    double& refentry = test_array.at(2);
    std::cout << "\n data at index 3: " << refentry;

    //test read-only reference entry "index"
    const double& ro_refentry = test_array.at(3);
    std::cout << "\n read-only data at index 3: " << refentry;

    //test resizing array
    Array arr_4(5, 2);
    std::cout << "\n original array: ";
    arr_4.print();
    std::cout << "\t resized array: ";
    arr_4.resize(10, true);
    arr_4.print();

    //test norm
    double norm = test_array.norm();
    std::cout << "\n norm: " << norm;

    //test sum
    double sum = test_array.sum();
    std::cout << "\n sum: " << sum;

    //test max
    double max = test_array.max();
    std::cout << "\n max: " << max;

    //test min
    double min = test_array.min();
    std::cout << "\n min: " << min;

    //test dot product
    double dot = test_array.dot(test_array_2);
    std::cout << "\n dot product: " << dot;

    //test sum of rhs and _data
    Array arr_5 = test_array.add(test_array_2);
    std::cout << "\n sum of arrays: ";
    arr_5.print();

    //test difference of rhs and _data
    Array arr_6 = test_array.sub(test_array_2);
    std::cout << "\n difference of arrays: ";
    arr_6.print();

    //test addition of arrays
    Array arr_7 = test_array + test_array_2;
    std::cout << "\n test of addition operator - sum of arrays: ";
    arr_7.print();


    //test subtraction of arrays
    Array arr_8 = test_array - test_array_2;
    std::cout << "\n test of subtraction operator - difference of arrays: ";
    arr_8.print();

    std::cout << "\n testing complete" << std::endl;

    return 0;
}
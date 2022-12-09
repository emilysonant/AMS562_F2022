#include "array.hpp"
#include <cmath>

//make default constructor

Array::Array() {
    _size = 0;
    _data = nullptr;
};

//copy constructor

Array::Array(const Array &other) {
    for(i = 0, i < _size, i++){
        _data[i] = other[i];
    }
}

//constructor with array size and the default initialization value

Array::Array(unsigned n, double v = 0.0) {
    _size = n;
    _data = new double[n];
    for(unsigned i=0; i<n; i++) {
        _data[i] = v*i;
    }
};

//deconstructer

Array::~Array() {
    delete [] _data;
};

//returns length of array

unsigned Array::size() const { 
    return _size; 
}

//returns data pointer of array

double Array::*data() {
    return _data;
}

//returns read-only pointer of array

const double Array::*data() const {
    return _data;
}

//for a rhs Array, the values are copied and checks that sizes are the same

void Array::copy(const Array &rhs) {
    //COPY ARRAY HERE
    bool status = true
    if (&rhs != _size){
        bool = false;
    }
}

//returns reference entry "index" of the data

double Array::&at(unsigned index) {
    return &_data[0]; 
}

//returns a read-only reference entry "index" of the data

const double Array::&at(unsigned index) const {
    return &_data[index];
}

//resizes the array
void Array::resize(unsigned new_size, bool prsv) {
    for(int i = 0; i < _size; i++){
        resize_data[i] = _data[i];
    }
    delete [] _data;
    _data = resize_data;
    _size = resize_size;
};

//returns the norm

double Array::norm() const {
    double x = 0;
    for(int i = 0, i < _size, i++){
        x += pow(_data[i], 2);
    }

    return x;
}

//returns the sum

double Array::sum() const {
    x = 0;
    for(i = 0, i < _size, i++){
        x += _data[i];
    }

    return x;
}

//returns the max

double Array::max() const {
    double max_data = 0;
    for(int i = 0; i < _size; i++){
        curr_data = _data[i];
        if (curr_data > max_data){
            max_data = curr_data;
        }
    }

    return max_data;
}

//returns the min

double Array::min() const {
    min_data = *_data[0];
    for(i = 1; i < size; i++){
        curr_data = _data[i];
        if (curr_data < min_data){
            min_data = curr_data;
        }
    }

    return min_data;
}

//returns the dot product

double Array::dot(const Array &rhs) const {
    for(int i = 0; i < _size; i++){
        x += rhs[i]*_data[i];
    }

    return x;
}

//returns an array that is the sum of rhs and _data

Array Array::add(const Array &rhs) const {

    double* sum_array = new double[_size];

    for(i = 0, i < _size, i++){
        sum_array[i] = rhs[i] + _data[i];
    }
}

delete sum_array;

//returns an array that is the difference of rhs and _data

Array Array::sub(const Array &rhs) const {

    double* diff_array = new double[_size];

    for(i = 0; i < _size; i++){
        diff_array[i] = rhs[i] + _data[i];
    }
}

delete diff_array;

//does terminal printing

void Array::print() const {};

//accessing operator

double & Array::operator[](const unsigned index) {};

//accessing const operator

const double & Array::operator[](const unsigned index) const {
    return _data[index];
};


Array Array::&operator=(const Array &other) {
    if(x != &other) {
        delete[] _data;
        _size = other._size;
        _data = new double[_size];
        for(unsigned i=0; i<_size; i++){
            _data[i] = other._data[i];
        }
    }
    return *x;
}

//free functions

// addition of two arrays

Array Array::operator+(const Array &lhs, const Array &rhs) {
    return lhs.add(rhs);
};

// subtraction of two arrays

Array Array::operator-(const Array &lhs, const Array &rhs) {
    return lhs.sub(rhs);
};

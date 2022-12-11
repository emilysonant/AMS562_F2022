#include "array.hpp"
#include "iostream"
#include <cmath>

//make default constructor
Array::Array() {
    _size = 0;
    _data = new double[0];
};

//copy constructor
Array::Array(const Array &other) {
    _size = other._size;
    _data = new double [_size];
    for(int i = 0; i < _size; i++){
        _data[i] = other._data[i];
    }
}

//constructor with array size and the default initialization value
Array::Array(unsigned n, double v) {
    _size = n;
    _data = new double[n];
    for(unsigned i=0; i<n; i++) {
        _data[i] = v*i;
    }
};

//destructor
Array::~Array() {
    delete [] _data;
};

//returns length of array
unsigned Array::size() const { 
    return _size; 
}

//returns data pointer of array
double* Array::data() {
    return _data;
}

//returns read-only pointer of array
const double* Array::data() const {
    return _data;
}

//for a rhs Array, the values are copied and checks that sizes are the same
void Array::copy(const Array &rhs) {
    bool status = true;
    if (rhs.size() == _size){
        for(int i = 0; i < _size; i++) {
            _data[i] = rhs._data[i];
        }
    }
    else{
        std::cout << "error: sizes are not equal";
    }
}

//returns reference entry "index" of the data
double& Array::at(unsigned index) {
    return _data[index]; 
}

//returns a read-only reference entry "index" of the data
const double& Array::at(unsigned index) const {
    return _data[index];
}

//resizes the array
void Array::resize(unsigned new_size, bool prsv) {
    double* resize_data = new double[new_size];
    if(prsv){
        for(int i = 0; i < _size; i++){
            resize_data[i] = _data[i];
      }
    }

    delete [] _data;
    _data = resize_data;
    _size = new_size;
};

//returns the norm
double Array::norm() const {
    double x = 0;
    for(int i = 0; i < _size; i++){
        x += pow(_data[i], 2);
    }
    x = sqrt(x);
    return x;
}

//returns the sum
double Array::sum() const {
    int x = 0;
    for(int i = 0; i < _size; i++){
        x += _data[i];
    }

    return x;
}

//returns the max
double Array::max() const {
    double max_data = 0;
    for(int i = 0; i < _size; i++){
        if (_data[i] > max_data){
            max_data = _data[i];
        }
    }

    return max_data;
}

//returns the min
double Array::min() const {
    int min_data = _data[0];
    for(int i = 1; i < _size; i++){
        if (_data[i] < min_data){
            min_data = _data[i];
        }
    }

    return min_data;
}

//returns the dot product
double Array::dot(const Array &rhs) const {
    double x = 0;
    for(int i = 0; i < _size; i++){
        x += rhs[i]*_data[i];
    }

    return x;
}

//returns an array that is the sum of rhs and _data
Array Array::add(const Array &rhs) const {
    Array sum_array(_size);
    for(int i = 0; i < _size; i++){
        sum_array[i] = rhs[i] + _data[i];
    }
    return sum_array;
}


//returns an array that is the difference of rhs and _data
Array Array::sub(const Array &rhs) const {
    Array diff_array(_size);
    for(int i = 0; i < _size; i++){
        diff_array[i] = rhs[i] - _data[i];
    }
    return diff_array;
}


//does terminal printing
void Array::print() const {
    std::cout << "size: " <<_size << "\t" << "data: ";
    for(int i = 0; i < _size; i++){
        std::cout << _data[i] << ", ";
    }
};

//accessing operator
double& Array::operator[](const unsigned index) {
    return _data[index];
};

//accessing const operator
const double & Array::operator[](const unsigned index) const {
    return _data[index];
};

Array& Array::operator=(const Array &other) {
        _size = other.size();
        _data = new double[_size];
        for(unsigned i=0; i<_size; i++){
            _data[i] = other[i];
        }
    return *this;
}


//free functions

// addition of two arrays
Array operator+(const Array &lhs, const Array &rhs) {
    return lhs.add(rhs);
};

// subtraction of two arrays
Array operator-(const Array &lhs, const Array &rhs) {
    return lhs.sub(rhs);
};
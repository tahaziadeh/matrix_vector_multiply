/*
 * MatrixVectorMultiply.hpp 
 *
 * Copyright (C) 2020
 * Author: Taha ZIADEH
 * Last modification: 27/04/2020
 * Version number: 1.0
 */

#ifndef MATRIX_VECTOR_MULTIPLY_HPP
#define MATRIX_VECTOR_MULTIPLY_HPP
#define dim(x) (sizeof(x) / sizeof((x)[0]))
class vector;
class matrix;
class matrix_wrong;
template <class M, class V>
void multiplyMatrixVector(M m, V v, V &result);
#endif
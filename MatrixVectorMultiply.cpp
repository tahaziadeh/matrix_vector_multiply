/*
 * MatrixVectorMultiply.cpp 
 *
 * Copyright (C) 2020
 * Author: Taha ZIADEH
 * Last modification: 27/04/2020
 * Version number: 1.0
 */

#include "MatrixVectorMultiply.hpp"

/**
 * Class matrix
 * This class handles the matrix objects 
 * It has a public 2-dimentional array member m
 */
class matrix
{
public:
    // bi-dimentional matrix (3x4) - single-precision
    float m[3][4];
};

/**
 * Class matrix_wrong
 * This class handles the wrong dimentional matrix objects 
 * It has a public 2-dimentional array member m
 */
class matrix_wrong
{
public:
    // bi-dimentional matrix (4x3) - single-precision
    float m[4][3];
};

/**
 * Class vector
 * This class handles the vector objects 
 * It has a public array member v
 */
class vector
{
public:
    // Uni-dimentional vector (4x1) - single-precision
    float v[4];
    bool isEmpty;
};

template <class M, class V>
void multiply(M m, V v, V &result)
{
    if (dim(m.m[0]) == dim(v.v))
    {
        result.isEmpty = false;
        // Loop over the rows of the matrix
        for (int i = 0; i < dim(m.m); i++)
        {
            // For each row, loop over the columns
            for (int j = 0; j < dim(m.m[0]); j++)
            {
                if (j == 0) //initialize the result cell to 0
                    result.v[i] = 0;

                // Multiply the column j in row i from the matrix m with the j element of the vector v
                result.v[i] += (m.m[i][j] * v.v[j]);
            }
        }
    }
    else
    {
        // The relative sizes do not match
        // The number of columns of the matrix is not equal to the number of elements in the vector
        result.isEmpty = true;
    }
}
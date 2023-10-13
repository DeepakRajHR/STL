#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED

#include <iostream>
#include <random>
#include <string_view>
#include <vector>

template<class T>
void print(const std::string_view msg, const std::vector<T> &v);
/**
 * Shuffles the elements of a vector using a random number generator.
 *
 * This function takes a reference to a vector of integers and shuffles its
 * elements randomly using a pseudo-random number generator. It ensures that the
 * elements are rearranged in a random order.
 *
 * @param v  A reference to the vector whose elements are to be shuffled.
 */
void shuffle(std::vector<int> &v);

/**
 * Initializes a vector of integers with consecutive values from 1 to
 * 'elements'.
 *
 * This function reserves memory for the vector to avoid reallocations and then
 * fills it with values from 1 to 'elements' using std::iota.
 * After that, it shuffles the elements within the vector.
 *
 * @param vector    A reference to the vector to be initialized.
 * @param elements  The number of elements to be generated and stored in the
 * vector. It determines the range of values from 1 to 'elements'.
 */
void init_vector(std::vector<int> &v);

void init_vector_with_alpha_numerics(std::vector<int> &v, int len);

#endif

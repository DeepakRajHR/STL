#include "util.h"

#include <algorithm> // for std::sort
#include <numeric> // for std::iota
#include <random>

void shuffle(std::vector<int>& v) {
  std::random_device rd;
  std::mt19937 generator(rd());

  std::shuffle(begin(v), end(v), generator);
}

int main (int argc, char *argv[]) {
  std::vector<int> v(10);

  // Populate the vector with random values
  std::iota(begin(v), end(v), 1);
  print("Values in vector to begin with", v);

  shuffle(v);
  print("Values in vector after a shuffle", v);

  // Sort the array
  std::sort(v.begin(), v.end());
  print("Values in vector after std::sort", v);

  shuffle(v);
  std::partial_sort(v.begin(), v.begin() + 5, v.end());
  print("Values in first five element in vector after std::partial_sort", v);

  std::nth_element(begin(v), v.begin() + 9, v.end());
  print("9th element in vector after std::nth_element", v);

  shuffle(v);
  // Note: we have to make heap first to sort using property of heap
  std::make_heap(v.begin(), v.end());
  std::sort_heap(v.begin(), v.end());
  print("Vector after std::sort_heap", v);

  return 0;
}

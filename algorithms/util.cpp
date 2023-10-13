#include "util.h"
#include <random>

template<class T>
void print(const std::string_view msg, const std::vector<T> &v) {
  std::cout << msg << ": [";
  for (auto &element : v) {
    std::cout << element << ", ";
  }
  std::cout << "]\n\n";
}

void shuffle(std::vector<int> &v) {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::shuffle(begin(v), end(v), generator);
}

void init_vector(std::vector<int> &v) {
  // reserve can throw std::length_error (element > max_size()) or
  // std::bad_alloc
  std::iota(v.begin(), v.end(), 1);
  shuffle(v);
}

void init_vector_with_alpha_numerics(std::vector<int> &v, int len) {
  std::random_device rd;
  std::mt19937 generator(rd());

  constexpr char alphanumerics[] = (
    "0123456789"
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  );

  v.reserve(len);

  for (int index=0; index<len; index++) {
    int pick_from = generator() % sizeof(alphanumerics) - 1;
    v[index] = alphanumerics[pick_from];
  }
}

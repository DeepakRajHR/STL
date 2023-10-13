/*
 * Learnings:
 * 1. Rotate takes three parameter: of course start and the end of the
 *    container, but also another iterator which is the "pivot" of rotation. The
 *    "pivot" is in the sense of the rotation algorithm based on the reversing
 *    the vector.
 *
 * 2. The methods (next or prev) *_permutation returns false if the next
 *    permutation is not lexicographically greater then the current alignment.
 *
 */

#include "util.h"

int main() {
  std::vector<int> v(10);
  init_vector(v);

  print("Initial vector", v);
  std::rotate(v.begin(), v.begin()+1, v.end());
  print("Rotated left by single element", v);

  std::rotate(v.begin(), v.begin() + 4, v.end());
  print("Rotate left by 4 element", v);

  std::random_device rd;
  std::mt19937 generator(rd());
  std::shuffle(v.begin(), v.end(), generator);
  print("Shuffle the elements", v);

  std::next_permutation(v.begin(), v.end());
  print("Next permutation", v);

  std::prev_permutation(v.begin(), v.end());
  print("Previous permutation", v);

  std::reverse(v.begin(), v.end());
  print("Reversed elements", v);

  return 0;
}

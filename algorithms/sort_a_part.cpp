/*
 * Learnings:
 * 1. Partition don't maintain the relative ordering (as it uses heap sort and
 * heap sort is not stable) 2.
 * 2. std::partition_point returns end of the iterator if there is no clear
 * partition point exists.
 */

#include "util.h"
#include <algorithm>

int main(int argc, char *argv[]) {
  std::vector<int> v(10);

  init_vector(v);
  print("Values in vector before std::sort", v);

  std::partial_sort(v.begin(), v.begin() + 5, v.end());
  print("Values in first five element in vector after std::partial_sort", v);

  shuffle(v);
  // Same as std::sort(begin, end) but slower as the impl of partial_sort uses
  // heap sort
  std::partial_sort(v.begin(), v.end(), v.end());

  std::nth_element(begin(v), v.begin() + 9, v.end());
  print("9th element in vector after std::nth_element", v);

  auto is_even = [](int i) { return i % 2 == 0; };
  std::partition(v.begin(), v.end(), is_even);
  print("Partition even or odd numbers", v);

  auto pp_iter = std::partition_point(v.cbegin(), v.cend(), is_even);
  auto pp_index = std::distance(v.cbegin(), pp_iter);
  std::cout << "Partition at index " << pp_index << " with value " << *pp_iter
            << "\n\n";

  shuffle(v);
  print("Shuffled v", v);
  // What happens if we try to find partition_point with no we defined boundary?
  pp_iter = std::partition_point(v.cbegin(), v.cend(), is_even);
  pp_index = std::distance(v.cbegin(), pp_iter);
  std::cout << "Partition at index " << pp_index << " with value " << *pp_iter
            << "\n";

  return 0;
}

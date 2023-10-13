/*
 * stable_*, is_*, is_*_until are the available algorithms can augments the
 * sort, permutation heap based algorithm
 */

#include "util.h"

int main() {
  std::vector<int> v(10);

  init_vector(v);

  print("Initial vector", v);
  std::stable_sort(v.begin(), v.end());
  print("Sorted (stable) v", v);

  shuffle(v);
  print("Reshuffle v", v);
  auto is_even = [](int e) { return e % 2 == 0; };
  std::stable_partition(v.begin(), v.end(), is_even);
  print("Stable partition on even numbers", v);

  if (std::is_partitioned(v.begin(), v.end(), is_even))
    std::cout << "v is partitioned based of even numbers\n";
  else
    std::cout << "v is not partitioned\n";

  if (std::is_sorted(v.begin(), v.end()) == true)
    std::cout << "v is sorted\n";
  else
    std::cout << "v is NOT sorted\n";

  std::make_heap(v.begin(), v.end());
  if (std::is_heap(v.begin(), v.end()) == true)
    std::cout << "v is a heap\n";
  else
    std::cout << "v is NOT a heap\n";

  // Similarly we have is_*_until
  std::sort(v.begin(), v.begin() + 5);
  auto sorted_itr = std::is_sorted_until(v.begin(), v.begin() + 5);
  std::cout << "v is sorted up to index "
            << std::distance(v.begin(), sorted_itr) << "\n";

  std::make_heap(v.begin(), v.begin() + 3);
  auto heaped_itr = std::is_heap_until(v.begin(), v.begin() + 4);
  std::cout << "v is heaped up to index "
            << std::distance(v.begin(), heaped_itr) << "\n";

  return 0;
}

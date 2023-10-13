/*
 * Learnings
 * 1. std:sort uses introsort where as std::partial_sort use heap sort
 * 2. Time complexity of std::sort is n*log(n)
 * 3. Time complexity of std::sort is n*log(m) where m = middle - first
 * 4. std::sort is faster then std::partial_sort
 * 5. std::sort_heap can only sort a vector which represents a heap
 *
 */

#include "util.h"
#include <algorithm> // for std::sort

int main(int argc, char *argv[]) {
  std::vector<int> v(10);
  init_vector(v);

  print("Values in vector before std::sort", v);
  std::sort(v.begin(), v.end());
  print("Sorted values", v);

  shuffle(v);
  std::sort(v.begin(), v.begin() + 6);
  print("Incorrectly sorted partial values for using std::sort for partailly "
        "sorting",
        v);

  shuffle(v);
  // Note: we have to make heap first to sort using property of heap
  std::make_heap(v.begin(), v.end());
  std::sort_heap(v.begin(), v.end());
  print("Vector after std::sort_heap", v);

  return 0;
}

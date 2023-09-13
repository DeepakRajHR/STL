#include "util.h"

#include <algorithm>

int main (int argc, char *argv[]) {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};

  print("Initial list", v);

  std::make_heap(begin(v), end(v));
  print("Max heap created using default comparator of make_heap", v);

  v.push_back(10);
  print("List with a new element and not adhearing to the heap property", v);
  std::push_heap(begin(v), end(v));
  print("Heapified list with new element", v);

  // Use pop_heap to get the max element the end of the array
  std::pop_heap(begin(v), end(v));
  int max_element = v.back();
  v.pop_back();

  std::cout << "Removed top-most element: " << max_element << "\n";
  print("Removed top-most element from the heap", v);

  auto greater_then_lambda = [](int a, int b) -> bool { return a > b; };
  std::make_heap(begin(v), end(v), greater_then_lambda);

  print("List after heapification using lambda", v);

  return 0;
}   



#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED

#include <iostream>
#include <string_view>
#include <vector>

/*
 * Mark this method as static to prevent ODR violation. This is not the optimul
 * solution as each TU will get it's own copy of function print. But we are not
 * optimising the code in our use case.
 * Source: https://stackoverflow.com/questions/66528686/basic-odr-violation-member-functions-in-h-files/66528927#66528927
 */
static void print(std::string_view msg, const std::vector<int> v) {
  std::cout << msg << ": [";
  for (auto& element: v) {
    std::cout << element << ", ";
  }
  std::cout << "]\n\n";
}

#endif

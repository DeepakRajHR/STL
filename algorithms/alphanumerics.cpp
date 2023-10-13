#include "util.h"

void print(const std::string_view msg, const std::vector<char> &v);

int main() {
  std::vector<char> v;
  int len = 20;

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
    v.push_back(alphanumerics[pick_from]);
  }
  print("After init", v);
  return 0;
}

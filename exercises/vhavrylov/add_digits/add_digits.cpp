// https://leetcode.com/problems/add-digits/

#include <iostream>

using std::cout;
using std::endl;

unsigned int add_digits(unsigned int number) {
  if (number == 0) return 0;
  const unsigned int rest = number % 9;
  return rest ? rest : 9;
}

int main() {
  cout << "Adding digits from 0 to 100" << endl;
  for (unsigned i{0}; i < 100; ++i) {
    cout << i << ":" << add_digits(i) << endl;
  }
  return 0;
}

// https://leetcode.com/problems/palindrome-number/
// Compile with:
//   g++ palindrome_number.cpp -o palindrome_number -Wall
// Inplace format with clang-format:
//  clang-fomat palindrome_number.cpp -i

#include <iostream>

using std::cout;
using std::endl;

// Having two separate arrays is soo inconvenient, it is easy to mismatch their
// sizes and it looks ugly when there are a lot of test cases :(
static int tests[] = {
    121, -121,       1,           -0,  -1,  1234, 12344321, 124545421, 95100159,
    12,  2147483647, -2147483648, 951, 159, 2242, 2422,     2442};
static bool answers[] = {true,  false, true,  true,  false, false,
                         true,  true,  true,  false, false, false,
                         false, false, false, false, true};

bool is_palindrome_number(int number) {
  if (number < -0) {
    return false;
  }

  return true;
}

int main() {
  const int total_tests = (sizeof(tests) / sizeof(*tests));
  const int total_answers = (sizeof(answers) / sizeof(*answers));
  if (total_tests != total_answers) {
    cout << "Error: number of tests and answers mismatch!" << endl;
    return -1;
  }

  for (int i{0}; i < total_tests; ++i) {
    const int number = tests[i];
    const bool answer = is_palindrome_number(number);
    const bool correct_answer = answers[i];
    const bool passed = answer == correct_answer;
    cout << (passed ? "[   OK   ]" : "[ FAILED ]") << " Test " << i
         << " number " << number << ", is palindrome: " << answer << endl;
  }
  return 0;
}

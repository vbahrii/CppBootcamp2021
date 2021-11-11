// https://leetcode.com/problems/palindrome-number/
// Compile with:
//   g++ palindrome_number.cpp -o palindrome_number -Wall
// Inplace format with clang-format:
//  clang-fomat palindrome_number.cpp -i

#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

bool is_palindrome_number(int number) {
  if (number < 0) {
    return false;
  }

  if (number == 0) {
    return true;
  }

  const int total_digits = ceil(log10(number));

  if (total_digits == 1) {
    return true;
  }

  static const int TEN = 10;
  int major_digit_idx = total_digits;
  int minor_digit_idx = 1;

  while (major_digit_idx > minor_digit_idx) {
    const int major_digit_rank = int(pow(TEN, major_digit_idx));
    const int minor_digit_rank = int(pow(TEN, minor_digit_idx));

    const int major_digit_value =
        number % major_digit_rank / (major_digit_rank / TEN);
    const int minor_digit_value =
        number % minor_digit_rank / (minor_digit_rank / TEN);

    if (major_digit_value != minor_digit_value) {
      return false;
    }

    ++minor_digit_idx;
    --major_digit_idx;
  }

  return true;
}

int main() {
  // Having two separate arrays is soo inconvenient, it is easy to mismatch
  // their sizes and it looks ugly when there are a lot of test cases :(
  static const int tests[] = {
      121,      -121,      1,        -0,   -1,         1234,
      12344321, 124545421, 95100159, 12,   2147483647, -2147483648,
      951,      159,       2242,     2422, 2442};
  static const bool answers[] = {true,  false, true,  true,  false, false,
                                 true,  true,  true,  false, false, false,
                                 false, false, false, false, true};

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

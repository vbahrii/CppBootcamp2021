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

  static const int TEN = 10;

  if (number < TEN) {
    return true;
  }

  const int total_digits = ceil(log10(number));

  if (number == pow(TEN, total_digits)) {
    // Handling cases when the number is 10, 100, 1000 ...
    return false;
  }

  int major_digit_idx = total_digits;
  int minor_digit_idx = 1;
  static const int MAX_ALLOWED_POWER_OF_TEN = log10(pow(2, sizeof(int) * 8));

  while (major_digit_idx > minor_digit_idx) {
    const int premajor_digit_rank = pow(TEN, major_digit_idx - 1);
    const int minor_digit_rank = pow(TEN, minor_digit_idx);
    const int preminor_digit_rank = pow(TEN, minor_digit_idx - 1);

    unsigned int major_digit_value =
        major_digit_idx > MAX_ALLOWED_POWER_OF_TEN
            ? (number / premajor_digit_rank)
            : (number % int(pow(TEN, major_digit_idx))) / premajor_digit_rank;
    unsigned int minor_digit_value =
        (number % minor_digit_rank) / preminor_digit_rank;

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
      121,      -121,       1,        -0,   -1,         1234,
      12344321, 124545421,  95100159, 12,   2147483647, -2147483648,
      951,      159,        2242,     2422, 2442,       10,
      100,      2147007412, 214707412};
  static const bool answers[] = {true,  false, true,  true,  false, false,
                                 true,  true,  true,  false, false, false,
                                 false, false, false, false, true,  false,
                                 false, true,  true};

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

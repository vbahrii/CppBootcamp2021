// https://leetcode.com/problems/length-of-last-word/

/*
Given a string s consisting of some words separated by some number of spaces,
return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.
Constraints:
    1 <= s.length <= 10^^4
    s consists of only English letters and spaces ' '.
    There will be at least one word in s.
*/

#include <iostream>

using std::cout;
using std::endl;
using std::size_t;

static const size_t MAX_ALLOWED_STRING_LENGTH{10000};
static const char DELIMITER{' '};

bool is_allowed_char(char ch) {
  return (('A' <= ch) && (ch <= 'z')) || (ch == DELIMITER);
}

int lengthOfLastWord(const char *s) {
  size_t last_word_size{0};
  bool was_previous_word_completed{true};
  for (size_t i{0}; i < MAX_ALLOWED_STRING_LENGTH; ++i) {
    const char ch = s[i];
    if (not is_allowed_char(ch)) {
      break;
    }
    if (ch == DELIMITER) {
      was_previous_word_completed = true;
    } else {
      if (was_previous_word_completed) {
        last_word_size = 0;
      }
      was_previous_word_completed = false;
      last_word_size += 1;
    }
  }
  return last_word_size;
}

int main() {

  auto str = "aa aa aaa     ";
  cout << str << " " << lengthOfLastWord(str) << endl;
}

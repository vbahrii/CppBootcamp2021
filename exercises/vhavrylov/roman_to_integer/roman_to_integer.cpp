// https://leetcode.com/problems/roman-to-integer/
// Using only string, native arrays, 'for', 'if-else', cout

#include <string>
#include <iostream>

std::string test_00 = "";
std::string test_01 = "I";
std::string test_03 = "III";
std::string test_04 = "IV";
std::string test_05 = "V";
std::string test_09 = "IX";
std::string test_10 = "X";
std::string test_12 = "XII";
std::string test_90 = "XC";
std::string test_900 = "CM";
std::string test_999 = "CMXCIX";
std::string test_3999 = "MMMCMXCIX";

int romanToInt(std::string s) {
    /// Expects a Roman number in range 1..3999.
    /// In case of invalid Roman number the output is garbage.

    /// For an empty string returns zero.
    if (s.empty()) return 0;
    
    const char I_1 = 'I';
    const char V_5 = 'V';
    const char X_10 = 'X';
    const char L_50 = 'L';
    const char C_100 = 'C';
    const char D_500 = 'D';
    const char M_1k = 'M';
    
    const int length = s.size();
    int digits[length];

    for (int i{0}; i<length; ++i) {
        if (s[i] == I_1) {
            digits[i] = 1;
        }
        else if (s[i] == V_5) {
            digits[i] = 5;
        }
        else if (s[i] == X_10) {
            digits[i] = 10;
        }
        else if (s[i] == L_50) {
            digits[i] = 50;
        }
        else if (s[i] == C_100) {
            digits[i] = 100;
        }
        else if (s[i] == D_500) {
            digits[i] = 500;
        }
        else if (s[i] == M_1k) {
            digits[i] = 1000;
        }
    }
    int previous_digit = digits[0];
    int result = previous_digit;
    for (int i{1}; i<length; ++i) {
        int current_digit = digits[i];
        if (current_digit <= previous_digit) {
            // Each next digit must be less or equal for a
            // "regular" Roman number such as MCLV or IIII
            result += current_digit;
        } else {
            // For the numbers with the internal subtraction,
            // a digit can be greater then the previous one,
            // and if so, it means we must subtract the previous
            // digit twice: once because it must not been added at all,
            // and the second time because it was intended to be subtracted
            // from the current digit.
            result -= 2 * previous_digit;
            // Still, in this case the current digit is processed exactly the same.
            result += current_digit;
        }
        previous_digit = current_digit;
    }
    
    return result;
}

int main() {

    std::cout << test_00 << " == " << romanToInt(test_00) << (romanToInt(test_00) == 0 ? ", passed" : ", failed") << std::endl;
    std::cout << test_01 << " == " << romanToInt(test_01) << (romanToInt(test_01) == 1 ? ", passed" : ", failed") << std::endl;
    std::cout << test_03 << " == " << romanToInt(test_03) << (romanToInt(test_03) == 3 ? ", passed" : ", failed") << std::endl;
    std::cout << test_04 << " == " << romanToInt(test_04) << (romanToInt(test_04) == 4 ? ", passed" : ", failed") << std::endl;
    std::cout << test_05 << " == " << romanToInt(test_05) << (romanToInt(test_05) == 5 ? ", passed" : ", failed") << std::endl;
    std::cout << test_09 << " == " << romanToInt(test_09) << (romanToInt(test_09) == 9 ? ", passed" : ", failed") << std::endl;
    std::cout << test_90 << " == " << romanToInt(test_90) << (romanToInt(test_90) == 90 ? ", passed" : ", failed") << std::endl;
    std::cout << test_999 << " == " << romanToInt(test_999) << (romanToInt(test_999) == 999 ? ", passed" : ", failed") << std::endl;
    std::cout << test_3999 << " == " << romanToInt(test_3999) << (romanToInt(test_3999) == 3999 ? ", passed" : ", failed") << std::endl;
    
    return 0;
}


// https://leetcode.com/problems/palindrome-number/

#include <iostream>

#define EXPECT(expr) if (!(expr)) \
    std::cout << "Test Failed " << "'" << #expr << "' " << __FILE__ << ":" << __LINE__ << std::endl;

class Solution {
public:
    bool isPalindrome(int x) {
       if (x < 0) 
           return false;
        
        if (x < 10)
            return true;
        
        int orig_x = x;
        long long reversed = 0;
        while (x > 0) {
            reversed *= 10;
            reversed += x % 10;
            x /= 10;
        }
        
        return (reversed == orig_x);
    }
};

int main()
{
    Solution s;
    EXPECT(s.isPalindrome(121) == true);
    EXPECT(s.isPalindrome(-121) == false);
    EXPECT(s.isPalindrome(1121) == false);
    EXPECT(s.isPalindrome(1221) == true);

    return 0;
}

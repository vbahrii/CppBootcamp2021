#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> seen;
    vector<int> twoSum(vector<int>& nums, int tint) {     
    for (int i = 0; i < (int)nums.size(); i++) {
        for(int j = 0; j < (int)nums.size(); j++)
        {
            if(i != j)
            if(nums[i]+nums[j] == tint)
            {
                cout << "Number item"<< std::endl;
                cout << "[" <<i <<","<< j <<  "]"<< std::endl;
                cout << "Value item"<< std::endl;
                cout << "{" <<nums[i] <<","<< nums[j] <<  "}"<< std::endl;                
                cout <<"------------------"<< endl;
                
                seen.insert({j, i});
                return {seen[nums[i]], i};
            }
        }
    }
    return {-1, -1}; 
    }
};
int main()
{
    Solution check;
    vector<int> nums_test {56,24,1,8,5,6,2563,7,0};
    
    check.twoSum(nums_test,9);   

    return 0;
}

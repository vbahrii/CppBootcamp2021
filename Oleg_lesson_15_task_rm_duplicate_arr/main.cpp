#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Duplicate {
public:    
    int remove_duplicate(vector<int>& nums) {     
        
        cout << "Count elemets - "<<unique(begin(nums), end(nums)) - begin(nums) << endl;        
        for(int i =0 ;i<unique(begin(nums), end(nums)) - begin(nums);i++)
            cout << "nums["<<i<<"] = " << nums[i] << endl;
            
       /* for(auto j  = unique(begin(nums), end(nums)); j <nums.size();j++ )
            nums[j] = 0x5F;*/ //how TODO static_cast with unique()?
         return unique(begin(nums), end(nums)) - begin(nums);
    }
};
int main()
{
    
    Duplicate remove;
    
    vector<int> remove_ar {1,2,2,3,3,4,4,5,6};    

    remove.remove_duplicate(remove_ar);
    return 0;
}

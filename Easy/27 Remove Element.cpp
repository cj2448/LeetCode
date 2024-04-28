#include <vector>

//  swap method
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.empty())
            return 0;

        unsigned int end = nums.size()-1;

        while (end >= 1 and nums[end] == val)
            --end;
        
        if (end == 0 and nums[end] == val)
            return 0;

        int i;
        for (i = 0; i < end; ++i) {
            if (nums[i] == val) {

                while (nums[end] == val)
                    --end;
                if (i > end)
                    return i;

                nums[i] = nums[end];
                nums[end] = val;
                --end;
            }
        }

        if (i > end)
            return i;
        else if (i == end and nums[i] == val)
            return i;
        else
            return i+1;
    }
};

//  Erase elements in place method
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         std::erase(nums, val);
//         return nums.size();
//     }
// };
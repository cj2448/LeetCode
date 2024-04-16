#include <algorithm>
#include <set>
#include <vector>


class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> triplet{};
        std::set<std::vector<int>> unique{};
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; ++i) {
            int j = i + 1;
            int k = nums.size()-1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                    unique.insert({nums[i], nums[j++], nums[k--]});
                else if (sum > 0)
                    --k;
                else
                    ++j;
            }
        }
        std::copy(unique.begin(), unique.end(), std::back_inserter(triplet));
        return triplet;
    }
};
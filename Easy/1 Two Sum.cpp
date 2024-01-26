#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_multimap;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 2)
            return vector<int>{0, 1};
        
        unordered_multimap<int, int> t;
        for (auto i = 0; i < nums.size(); ++i)
            t.insert({nums[i], i});
        
        for (const auto& e : t) {
            auto temp = t.find(target - e.first);
            if (temp != t.end() and e.second != temp->second)
                return vector<int>{e.second, temp->second};
            
        }
        
        return vector<int>{0, 3};
    }
};
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max = 0;
        unsigned int left = 0;
        unsigned int right = height.size()-1;
    
        while (left != right) {
            unsigned int smaller = std::min(height[left], height[right]);
            unsigned int temp = smaller * (right - left);
            
            if (temp > max)
                max = temp;

            if (smaller == height[left])
                ++left;
            else
                --right;
        }
        
        return max;
    }
};
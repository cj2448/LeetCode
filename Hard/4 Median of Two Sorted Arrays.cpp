#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty())
            if (nums2.size() % 2 == 1)
                return (double)nums2[nums2.size()/2];
            else
                return (double)(nums2[nums2.size()/2-1] + nums2[nums2.size()/2])/2;
            

        else if (nums2.empty())
            if (nums1.size() % 2 == 1)
                return (double)nums1[nums1.size()/2];
            else
                return (double)(nums1[nums1.size()/2-1] + nums1[nums1.size()/2])/2;
            

        vector<int> merged;
        int midpoint = std::ceil((double)(nums1.size() + nums2.size())/2);
        unsigned int itr1 = 0;
        unsigned int itr2 = 0;
        unsigned int count = 0;
        
        do {
            if (nums1[itr1] < nums2[itr2]) {
                merged.push_back(nums1[itr1++]);
                ++count;
            }

            else {
                merged.push_back(nums2[itr2++]);
                ++count;
            }
        } while (count != midpoint and itr1 < nums1.size() and itr2 < nums2.size());


        while (count != midpoint and itr1 < nums1.size()) {
            merged.push_back(nums1[itr1++]);
            ++count;
        }

        while (count != midpoint and itr2 < nums2.size()) {
            merged.push_back(nums2[itr2++]);
            ++count;
        }

        if ((nums1.size() + nums2.size()) % 2)
            return merged.back();
            
        if (itr1 >= nums1.size())
            merged.push_back(nums2[itr2]);
        else if (itr2 >= nums2.size())
            merged.push_back(nums1[itr1]);
        else if (nums1[itr1] < nums2[itr2])
            merged.push_back(nums1[itr1]);
        else
            merged.push_back(nums2[itr2]);

        double median = (double)(merged[merged.size()-1] + merged[merged.size()-2])/2;

        return median;
    }
};
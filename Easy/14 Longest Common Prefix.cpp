#include <algorithm>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1 || strs[0] == "")
            return strs[0];


        std::string lcp = strs[0];
        char first = strs[0][0];

        for (auto i = 1; i < strs.size(); ++i) {
            if (strs[i] == "")
                return "";
            else if (strs[i][0] != first)
                return "";
            else {
                auto limit = std::min(lcp.size(), strs[i].size());
                unsigned int temp = 0;
                for (auto j = 0; j < limit; ++j) {
                    if (strs[i][j] == lcp[j])
                        ++temp;
                    else
                        break;
                }
                lcp = lcp.substr(0, temp);
            }
        }
        
        return lcp;
    }
};

#include <string>
#include <algorithm>

using std::string;
using std::fill_n;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        
        bool seen[128] = {false};
        auto max = 0;
        
        for (auto i = 0; i < s.size()-1; ++i) {
            auto temp = 0;
            
            if (!(seen[s[i]])) {
                seen[s[i]] = true;
                ++temp;
                
                for (auto j = i+1; j < s.size(); ++j) {
                    if (!(seen[s[j]])) {
                        seen[s[j]] = true;
                        ++temp;
                    }
                    
                    else {
                        if (temp > max)
                            max = temp;
                        fill_n(seen, 128, false);
                        break;
                    }
                }
                
                if (temp > max)
                    max = temp;
                fill_n(seen, 128, false);
            }
        }
        
        return max;
    }
};
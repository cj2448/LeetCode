#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    std::vector<int> buildLastFunction(const std::string& pattern) {
        const int N_ASCII = 128;
        std::vector<int> last(N_ASCII);

        for (unsigned int i = 0; i < N_ASCII; ++i)
            last[i] = -1;

        for (unsigned i = 0; i < pattern.size(); ++i)
            last[pattern[i]] = i;
        
        return last;
    }

public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i = m - 1;

        if (m > n)
            return -1;

        int j = m - 1;
        std::vector<int> last = buildLastFunction(needle);

        do {
            if (needle[j] == haystack[i])
                if (j == 0) return i;
                else {
                    --i; --j;
                }

            else {
                i = i + m - std::min(j, 1 + last[haystack[i]]);
                j = m - 1;
            }

        } while (i <= n - 1);
	
	return -1;
    }
};
#include <string>
#include <map>

using std::string;
using std::map;

class Solution {
public:
    string intToRoman(int num) {
        std::map<int, string> numerals{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        std::string ans{};
        for (auto ritr = numerals.rbegin(); ritr != numerals.rend(); ++ritr) {
            while(num >= ritr->first) {
                num -= ritr->first;
                ans += ritr->second;
            }
        }
        
        return ans;
    }
};
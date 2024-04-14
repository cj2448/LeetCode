#include <limits>
#include <vector>
#include <cctype>
#include <string>
#include <cmath>

using std::vector;
using std::string;

//  slow/inefficient solution redo at some point;
class Solution {
public:
    int myAtoi(string s) {
        bool checked_parity = false;
        bool is_neg = false;
        vector<short> digits{};
        long num{0};
        int ans{0};

        for (int i = 0; i < s.size(); ++i) {
            if (isspace(s[i])) {
                if (checked_parity)
                    break;
                continue;
            }

            else if (s[i] == '+' or s[i] == '-') {
                if (!checked_parity) {
                    checked_parity = true;
                    if (s[i] == '-')
                        is_neg = true;
                }
                else
                    break;
            }

            else if (isdigit(s[i])) {
                if (!checked_parity && digits.empty())
                    checked_parity = true;

                if (s[i] == '0' && digits.empty())
                    continue;
                
                digits.push_back(s[i]-'0');
            }
            else
                break;
        }

        if (digits.size() > 10) {
            if (is_neg)
                return std::numeric_limits<int>::min();
            return std::numeric_limits<int>::max();
        }

        unsigned int place = digits.size()-1;
        for (const auto & e: digits)
            num += e*pow(10, place--);

        if (is_neg)
            num *= -1;
        
        if (num > std::numeric_limits<int>::max())
            return std::numeric_limits<int>::max();
        else if (num < std::numeric_limits<int>::min())
            return std::numeric_limits<int>::min();

        return num;
    }
};
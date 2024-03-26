#include <deque>

using std::deque;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else if (x < 10)
            return true;
        
        deque<int> digits{};
        while (x != 0) {
            digits.push_front(x%10);
            x /= 10;
        }

        while (!digits.empty()) {
            if (digits.size() == 1) {
                return true;
                break;
            }

            else if (digits.front() != digits.back())
                break;

            digits.pop_front();
            digits.pop_back();
        }
        if (digits.empty())
            return true;

        return false;
    }
};
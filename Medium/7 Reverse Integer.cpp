#include <limits>

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            if (rev < std::numeric_limits<int>::min() / 10 || rev > std::numeric_limits<int>::max() / 10)
                return 0;

            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return rev;
    }
};
#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st{};

        if (s.size() == 1)
            return false;

        for (const auto &ch : s) {
            if (ch == '(' or ch =='[' or ch == '{')
                st.push(ch);

            else {
                if (st.empty())
                    return false;

                switch(ch) {
                    case ')': if (st.top() != '(') return false; break;
                    case ']': if (st.top() != '[') return false; break;
                    case '}': if (st.top() != '{') return false; break;
                }
                
                st.pop();
            }
        }

        if (!st.empty())
            return false;

        return true;
    }
};
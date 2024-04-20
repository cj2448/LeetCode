#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    void dfs(vector<string> & v, int left, int right, string s, const int & n) {
        if (s.size() == n*2) {
            v.push_back(s);
            return;
        }

        if (left < n)
            dfs(v, left + 1, right, s + "(", n);
        
        if (right < left)
            dfs(v, left, right + 1, s + ")", n);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> comb;
        dfs(comb, 0, 0, "", n);
        return comb;
    }
};
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>v(numRows);
        bool flag=true;
        for(int i=0;i<s.size();){
            if(flag){
                for(int j=0;j<numRows &&i<s.size();j++)
                v[j].push_back(s[i++]);
            }
            else{
                for(int j=numRows-2;j>=1 && i<s.size();j--)v[j].push_back(s[i++]);
            }
            flag=!flag;
        }
        string ans="";
        for(auto &x:v)ans+=x;
        return ans;
    }
};
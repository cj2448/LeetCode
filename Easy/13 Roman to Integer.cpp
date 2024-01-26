#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> numerals{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i < s.size()-1) {
                if (s[i] == 'I') {
                    if (s[i+1] == 'V') {
                        num += 4;
                        ++i;
                    }
                    
                    else if (s[i+1] == 'X') {
                        num += 9;
                        ++i;
                    }
                    
                    else
                        num += numerals[s[i]];
                }
                
                else if (s[i] == 'X') {
                    if (s[i+1] == 'L') {
                        num += 40;
                        ++i;
                    }
                    
                    else if (s[i+1] == 'C') {
                        num += 90;
                        ++i;
                    }
                    
                    else
                        num += numerals[s[i]];
                }
                
                else if (s[i] == 'C') {
                    if (s[i+1] == 'D') {
                        num += 400;
                        ++i;
                    }
                    
                    else if (s[i+1] == 'M') {
                        num += 900;
                        ++i;
                    }
                    
                    else
                        num += numerals[s[i]];
                }
                
                else {
                    num += numerals[s[i]];
                }
            }
            
            else {
                num += numerals[s[i]];
            }
        }
        
        return num;     
    }
};
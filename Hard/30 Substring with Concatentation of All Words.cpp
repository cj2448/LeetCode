#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using std::vector;
using std::string;
using std::set;

//  functioning but currently way too slow since this solution finds all potential permutations before string matching
//  faster and more efficient solution would be using a sliding window
//  REVISIT QUESTION AT SOME TIME

class Solution {
void permutations(set<string>& p, vector<string> words, int l, int h) {
    if (l == h) {
        std::string build = "";
        for(const auto &e : words)
            build += e;
        p.insert(build);
        return;
    }

    for (int i = l; i <= h; ++i) {
        swap(words[l], words[i]);
        permutations(p, words, 1 + l, h);
        swap(words[l], words[i]);
    }
}

set<string> permute(vector<string>& words) {
    set<string> p;
    permutations(p, words, 0, words.size()-1);
    return p;
}

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        set<string> p = permute(words);
        vector<int> sub_indices{};

        std::unordered_map<char, std::vector<unsigned int>> dict;
        for (unsigned int i = 0; i < s.size(); ++i) {
            if (dict.find(s[i]) != dict.end())
                dict[s[i]].push_back(i);
            
            else
                dict[s[i]] = {i};
        }

        int s_size = s.size();
        for (const auto &e : p) {
            if (dict.find(e[0]) != dict.end()) {
                for (const auto& v : dict[e[0]]) {
                    if (s_size - v >= e.size() and s.substr(v, e.size()) == e) {
                        sub_indices.push_back(v);
                    }
                }
            }
        }

        return sub_indices;
    }
};
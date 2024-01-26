#include <stack>
#include <utility>

using std::stack;
using std::pair;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;

        stack<pair<TreeNode*, int>> s;
        s.push(pair<TreeNode*, bool>(root, false));
        while(!s.empty()) {
            pair<TreeNode*, bool> current = s.top();
            s.pop();

            if (current.first->right != nullptr)
                s.push(pair<TreeNode*, bool>(current.first->right, false));
            if (current.first->left != nullptr)
                s.push(pair<TreeNode*, bool>(current.first->left, true));
            
            if (current.second && current.first->left == nullptr and current.first->right == nullptr)
                sum += current.first->val;
        }

        return sum;
    }
};  
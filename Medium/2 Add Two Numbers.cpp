#include <vector>

using std::vector;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<short> v1, v2, v3;
        while (l1) {
            v1.push_back(l1->val);
            l1 = l1->next;
            
        }
        
        while (l2) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }

        auto i = v1.begin();
        auto j = v2.begin();
        bool carry = 0;
        
        
        while (i != v1.end() and j != v2.end()) {
            short sum = *i + *j;
            if (carry != 0) {
                sum += carry;
                carry = 0;
            }
            
            if (sum >= 10) {
                carry = sum / 10;
                sum %= 10;
            }
            
            v3.push_back(sum);
            ++i; ++j;
        }
        

        while (i != v1.end()) {
            short temp = *i;
            if (carry != 0) {
                temp += carry;
                carry = 0;
            }
            
            if (temp >= 10) {
                carry = temp / 10;
                temp %= 10;
            }
            
            v3.push_back(temp);
            ++i;
        }
        
        while (j != v2.end()) {
            short temp = *j;
            if (carry != 0) {
                temp += carry;
                carry = 0;
            }
            
            if (temp >= 10) {
                carry = temp / 10;
                temp %= 10;
            }
            
            v3.push_back(temp);
            ++j;
        }
        
        if (carry)
            v3.push_back(carry);
        
        auto itr = v3.begin();
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        
        while (itr != v3.end()) {
            temp->val = *itr;
            ++itr;
            if (itr == v3.end())
                break;
            
            temp->next = new ListNode();
            temp = temp->next;
        }
        
        return ans;
    }
};
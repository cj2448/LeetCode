
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* temp = new ListNode(0, head);
        ListNode* prev = temp;
        ListNode* curr = head;

        while (curr and curr->next) {  //  while 2 swappable pairs exist
            //  update next ptrs to two nodes ahead
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr; //  make 2nd node point to the 1st node

            //  update to next pair of nodes
            prev = curr;
            curr = curr->next;
        }
        
        return temp->next;
    }
};
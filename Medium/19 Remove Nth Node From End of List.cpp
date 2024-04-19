
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        unsigned int size = 0;

        auto itr = head;
        while (itr != nullptr) {
            itr = itr->next;
            ++size;
        }

        itr = head;
        if (n == size) {
            if (itr->next == nullptr) {
                delete itr;
                return nullptr;
            }

            else {
                auto temp = itr;
                itr = itr->next;
                delete temp;
                return itr;
            }
        }

        for (auto i = 0; i < size - n - 1; ++i)
            itr = itr->next;

        auto temp = itr;
        itr = itr->next;
        temp->next = itr->next;
        delete itr;

        return head;
    }
};
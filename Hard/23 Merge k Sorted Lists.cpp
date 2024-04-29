 //  Constructing Linked List from Minheap
 //  Time Complexity: O(n^2log(k)) ??? tbh idk lol
 //  Space Compelxity: O(n)

#include <vector>
#include <queue>

class Solution {
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        auto cmp = [](const ListNode* l, const ListNode* r) { return l->val > r->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (const auto l : lists) {
            ListNode* temp = l;
            while (temp) {
                pq.push(temp);
                temp = temp->next;
            }
        }
        
        if (pq.empty())
            return nullptr;

        ListNode* head = pq.top();
        pq.pop();

        auto temp = head;
        for (; !pq.empty(); pq.pop()) {
            temp->next = pq.top();
            temp = temp->next;
        }
        temp->next = nullptr;

        return head;
    }
};
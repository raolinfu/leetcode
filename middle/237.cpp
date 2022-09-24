#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;

        while (next)
        {
            node->val = next->val;
            if (next->next == nullptr)
                break;
            node = next;
            next = node->next;
        }
        
        node->next = nullptr;
    }
};

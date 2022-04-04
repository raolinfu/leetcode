struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dumpy;
        dumpy.next = head;
        head = head->next;
        dumpy.next->next = nullptr;
        while (head) {
            ListNode* cur = head;
            head = head->next;
            ListNode* node = dumpy.next;
            ListNode* pre = &dumpy;
            while (node) {
                if (node->val > cur->val) {
                    pre->next = cur;
                    cur->next = node;
                    break;
                }
                pre = node;
                node = node->next;
            }
            if (node == nullptr) {
                pre->next = cur;
                cur->next = nullptr;
            }
        }

        return dumpy.next;
    }
};


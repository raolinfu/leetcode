
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dumpy;
        ListNode* pre = &dumpy;
        while (head) {
            int i = 0;
            ListNode* h = head;
            while (i < k - 1 && head) {
                head = head->next;
                i++;
            }

            if (i == k - 1 && head) {
                ListNode* next = head->next;
                ListNode* last = reverse(h, k);
                pre->next = last;
                pre = h;
                head = next;
            } else {
                pre->next = h;
                break;
            }
        }

        return dumpy.next;
    }

    ListNode* reverse(ListNode* head, int k) {
        if (k == 1)
            return head;
        ListNode* last = reverse(head->next, k - 1);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};

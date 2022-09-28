
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* pre = &head;
        int c = 0;
        while (l1 || l2)
        {
            int n1 = 0;
            int n2 = 0;
            if (l1) {
                n1 = l1->val;
                l1 = l1->next;
            }

            if (l2) {
                n2 = l2->val;
                l2 = l2->next;
            }
            
            pre->next = new ListNode((n1 + n2 + c) % 10);
            c = (n1 + n2 + c) / 10;
            pre = pre->next;
        }

        if (c > 0) {
            pre->next = new ListNode(c);
        }
        
        return head.next;
    }
};
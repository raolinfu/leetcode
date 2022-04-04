
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* slow = getSlow(head);
        ListNode* middle = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(middle);

        return merge(left, right);
    }

    ListNode* getSlow(ListNode* head) {
        ListNode dumpy;
        dumpy.next = head;
        ListNode* slow = &dumpy;
        ListNode* fast = &dumpy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow == &dumpy? dumpy.next: slow;
    }

    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode dumpy;
        ListNode* pre = &dumpy;
        while (l || r) {
            if (l && r) {
                if (l->val <= r->val) {
                    pre->next = l;
                    pre = l;
                    l = l->next;
                } else {
                    pre->next = r;
                    pre = r;
                    r = r->next;
                }
            } else if (l){
                pre->next = l;
                break;
            } else if (r) {
                pre->next = r;
                break;
            }
        }

        return dumpy.next;
    }
};

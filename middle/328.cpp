
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode odd;
        ListNode even;
        ListNode* odd_pre = &odd;
        ListNode* even_pre = &even;
        bool isOdd = true;
        while (head) {
            if (isOdd) {
                odd_pre->next = head;
                odd_pre = head;
            } else {
                even_pre->next = head;
                even_pre = head;
            }
            head = head->next;
            isOdd = !isOdd;
        }
        even_pre->next = nullptr;
        odd_pre->next = even.next;

        return odd.next;
    }
};

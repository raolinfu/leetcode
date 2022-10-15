#include <cstddef>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		ListNode h1(0);
		ListNode h2(0);
		ListNode* p1 = &h1;
		ListNode* p2 = &h2;
		while (head) {
			if (head->val < x) {
				p1->next = head;
				p1 = p1->next;
			} else {
				p2->next = head;
				p2 = p2->next;
			}

			head = head->next;
		}

		p1->next = h2.next;
		p2->next = nullptr;

		return h1.next;
    }
};

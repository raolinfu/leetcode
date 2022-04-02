#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return;
		int n = 0;
		ListNode* h = head;
		while (h) {
			n++;
			h = h->next;
		}
		ListNode* f = head;
		int i = 1;
		while (i < (n + 1)/ 2) {
			f = f->next;
			i++;
		}
		ListNode* s = f->next;
		f->next = nullptr;
        f = head;

		s = reverseList(s);
   		i = 0;
		ListNode cur;
		head = &cur;
		while (f || s) {
			if (i % 2 == 0) {
				head->next = f;
				head = f;
				f = f->next;
			} else {
				head->next = s;
				head = s;
				s = s->next;
			}
            i++;
		}
    }

	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* last = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return last;
	}


    void reorderList1(ListNode* head) {
		ListNode* cur = head;
		int n = 0;
		while (cur) {
			cur = cur->next;
			n++;
		}
		sort(head, n);
    }

	ListNode* sort(ListNode* head, int n) {
		if (n == 1)
			return head;
		int l1 = n / 2;
		int l2 = n - l1;
		ListNode* middle = getMiddle(head, l1);
		ListNode* h1 = sort(head, l1);
		ListNode* h2 = sort(middle, l2);
		return merge(h1, l1, h2, l2);
	}

	ListNode* merge(ListNode* h1, int l1, ListNode* h2, int l2) {
		ListNode dumpy;
		ListNode* cur = &dumpy;
		while (l1 || l2) {
			if (dumpy.next == nullptr) {
				dumpy.next = h1->val > h2->val? h2: h1;
			}
			if (l1 && l2) {
				if (h1->val < h2->val) {
					cur->next = h1;
					cur = h1;
					h1 = h1->next;
					l1--;
				} else {
					cur->next = h2;
					cur = h2;
					h2 = h2->next;
					l2--;
				}
			}
			else if (l1) {
				cur->next = h1;
				cur = h1;
				h1 = h1->next;
				l1--;
			}else if (l2) {
				cur->next = h2;
				cur = h2;
				h2 = h2->next;
				l2--;
			}
		}

		return dumpy.next;
	}

	ListNode* getMiddle(ListNode* head, int l) {
		while (l > 0) {
			head = head->next;
			l--;
		}
		return head;
	}
};

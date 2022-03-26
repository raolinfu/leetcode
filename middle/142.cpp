#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		int i = 0;
		while (fast && fast->next) {
			i++;
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) {
				ListNode* cur = head;
				while (cur != slow) {
					cur = cur->next;
					slow = slow->next;
				}
				return cur;
			}
		}
        
		return nullptr;
    }
};

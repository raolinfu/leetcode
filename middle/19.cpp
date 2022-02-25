
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dumpy;
		dumpy.next = head;
		ListNode* fast = &dumpy;
		ListNode* slow = &dumpy;
		int i = 0;
		while(fast && i < n + 1){
			fast = fast->next;
			i++;
		}

		if(i < n)
			return head;

		while(fast){
			fast = fast->next;
			slow = slow->next;
		}

		if(slow->next)
		{
			ListNode* tmp = slow->next;
			slow->next = tmp->next;
			delete tmp;
		}

		return dumpy.next;
    }
};


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode head;
		ListNode *h1 = reverseList(l1);
		ListNode *h2 = reverseList(l2);
		int c = 0;
		int cur = 0;
		while(h1 && h2){
			cur = (h1->val + h2->val + c) % 10;
			c = (h1->val + h2->val + c) / 10;
			ListNode *node = new ListNode(cur);
			node->next = head.next;
			head.next = node;
			h1 = h1->next;
			h2 = h2->next;
		}
		ListNode *h = h1 == nullptr? h2: h1;
		while(h){
			cur = (h->val + c) % 10;
			c = (h->val + c) / 10;
			ListNode *node = new ListNode(cur);
			node->next = head.next;
			head.next = node;
			h = h->next;
		}
		if(c){
			ListNode *node = new ListNode(c);
			node->next = head.next;
			head.next = node;
		}

		return head.next;
    }
	ListNode* reverseList(ListNode* l){
		ListNode* pre = l;
		ListNode *next = l->next;
		l->next = nullptr;
		while(next){
			l = next;
			next = l->next;
			l->next = pre;
			pre = l;
		}
		return pre;
	}
};

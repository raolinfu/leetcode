#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Status {
	int val;
	ListNode *ptr;
	bool operator < (const Status &rhs) const {
		return val > rhs.val;
	}
};


ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode head;
	ListNode *tail = &head;
    priority_queue <Status> q;
	for(auto node : lists){
		q.push({node->val, node});
	}
	while(!q.empty()){
		ListNode *top = q.top().ptr;
		tail->next = top;
		tail = top;
		q.pop();
		if(top->next)
			q.push({top->next->val, top->next});
	}
	return head.next;
}

int main(){
	vector<ListNode*> lists;
	mergeKLists(lists);

	return 0;
}

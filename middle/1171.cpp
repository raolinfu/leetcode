#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeZeroSumSublists(ListNode* head) {
	ListNode root;
	root.next = head;
	unordered_map<int, pair<int, ListNode*>> mp;
	vector<int> sums;
	int sum = 0;
	mp[sum] = {-1, &root};
	while(head){
		sum += head->val;
		// 之前出现过 要开始删除了
		if(mp.count(sum)){
			cout<< "val: "<< head->val<< "sum: "<< sum<< endl;
			int len = sums.size();
			int idx = mp[sum].first;
			ListNode *p = mp[sum].second;
			// 删除操作
			p->next = head->next;
			for(int i = len - 1; i > idx; i--){
				mp.erase(sums[i]);
				sums.pop_back();
			}
			if(sums.size())
				sum = sums.back();
			else
				sum = 0;
		}else {
			int len = sums.size();
			mp[sum] = {len, head};
			sums.push_back(sum);
		}

		head = head->next;
	}

	return root.next;
}

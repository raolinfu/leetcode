#include<vector>
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<ListNode*> splitListToParts(ListNode* head, int k) {
	vector<ListNode*> res(k, nullptr);
	ListNode root;
	root.next = head;
	int len = 0;
	while(head){
		len++;
		head = head->next;
	}
	head = root.next;
	// 长度不大于k的情况
	if(len <= k){
		int i = 0;
		while(head){
			ListNode *next = head->next;
			res[i] = head;
			head->next = nullptr;
			head = next;
			i++;
		}
		return res;
	}
	int n = len / k;
	int m = len % k;
	// 前m个的长度为n + 1
	for(int i = 0; i < m; i++){
		res[i] = head;
		for(int j = 0; j < n; j++){
			head = head->next;
		}
		ListNode *next = head->next;
		head->next = nullptr;
		head = next;
	}
	// 后k - m的长度为n
	for(int i = m; i < k; i++){
		res[i] = head;
		for(int j = 0; j < n - 1; j++){
			head = head->next;
		}
		ListNode *next = head->next;
		head->next = nullptr;
		head = next;
	}

	return res;
}

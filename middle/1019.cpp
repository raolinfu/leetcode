#include<vector>
#include<stack>
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
    vector<int> nextLargerNodes(ListNode* head) {
		ListNode *p = head;
		int cnt = 0;
		while(p){
			cnt++;
			p = p->next;
		}
		vector<int> ans(cnt, 0);
		stack<pair<int, ListNode*>> stk;
		p = head;
		for(int i = 0; i < cnt; i++){
			while(!stk.empty() && stk.top().second->val < p->val){
				ans[stk.top().first] = p->val;
				stk.pop();
			}
			stk.push({i, p});
			p = p->next;
		}

		return ans;
    }
};

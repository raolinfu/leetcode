#include<unordered_map>
#include<queue>
#include<climits>
#include<vector>
#include<unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		unordered_set<TreeNode*> st;
		getDepath(root, nullptr, 0);
		for(auto [k, v]: deepth){
			if(v == maxDeepth)
				q.push(k);
		}
		while(!q.empty()){
			int cnt = q.size();
			st.clear();
			for(int i = 0; i < cnt; i++){
				auto k= q.front();
				st.insert(k);
				q.push(parent[k]);
				q.pop();
			}
			if(st.size() == 1){
				return *st.begin();
			}
		}

		return root;
    }
	void getDepath(TreeNode* root, TreeNode* p, int d){
		if(root == nullptr)
			return;
		d++;
		parent[root] = p;
		maxDeepth = max(maxDeepth, d);
		deepth[root] = d;
		getDepath(root->left, root, d);
		getDepath(root->right, root, d);
	}
private:
	unordered_map<TreeNode*, TreeNode*> parent;
	unordered_map<TreeNode*, int> deepth;
	queue<TreeNode*> q;
	int maxDeepth = INT_MIN;
};

#include<vector>
#include<unordered_set>
using namespace std;
// 二叉树的右视图 本质是每层的最有节点
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void process(TreeNode* root , vector<int> &res, unordered_set<int> &s, int level);
vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	unordered_set<int> s;
	process( root, res, s, 0);
	return res;
}

void process(TreeNode* root , vector<int> &res, unordered_set<int> &s, int level){
	if(!root)
		return;
	if(s.find(level) == s.end()){
		s.insert(level);
		res.push_back(root->val);
	}

	process( root->right , res, s, level + 1);
	process( root->left, res, s, level + 1);

}

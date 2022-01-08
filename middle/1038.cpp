#include<stack>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
void process(TreeNode* root, stack<TreeNode*>& st) ;

TreeNode* bstToGst(TreeNode* root) {
	int sum = 0;
	stack<TreeNode*> st;
	process(root, st);
	while(!st.empty()){
		sum += st.top()->val;
		st.top()->val = sum;
		st.pop();
	}
	return root;
}

void process(TreeNode* root, stack<TreeNode*>& st) {
	if(root == nullptr)
		return;
	process(root->left, st);
	st.push(root);
	process(root->right, st);
}

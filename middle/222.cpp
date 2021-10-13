struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void process(TreeNode* root, int &res);
int countNodes(TreeNode* root) {
	int res = 0;	
	process(root, res);
	return res;
}

void process(TreeNode* root, int &res){
	if(!root)
		return;
	res++;
	process(root->left, res);
	process(root->right, res);
}

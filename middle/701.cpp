
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
	// 注意这里
	if(root == nullptr)
		return new TreeNode(val);
	TreeNode* cur = root;
	while(true){
		if(val > cur->val){
			if(cur->right == nullptr){
				TreeNode* newNode = new TreeNode(val);
				cur->right = newNode;
				break;
			}else{
				cur = cur->right;
			}
		}else{
			if(cur->left == nullptr){
				TreeNode* newNode = new TreeNode(val);
				cur->left = newNode;
				break;
			}else{
				cur = cur->left;
			}
		}
	}

	return root;
}

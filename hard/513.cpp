#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void process(TreeNode* root, int &res, int &maxHight, int hight);
int findBottomLeftValue(TreeNode* root) {
	int res;
	int maxHight = 0;
	process(root, res, maxHight, 0);

	return res;
}

void process(TreeNode* root, int &res, int &maxHight, int hight){
	if(root == nullptr)
		return;
	hight++;
	if(root->left == nullptr && root->right == nullptr){
		if(hight > maxHight){
			res = root->val;
			maxHight = hight;
		}
	}
	process(root->left, res, maxHight, hight);
	process(root->right, res, maxHight, hight);
	
}

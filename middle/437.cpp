#include<unordered_map>
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

void process(TreeNode* root, unordered_map<int, int> mp, int &res, int &targetSum, int preSum);
int pathSum(TreeNode* root, int targetSum) {
	int res = 0;
	unordered_map<int, int>mp;
	// 别漏了这里
	mp[0] = 1;
	process(root, mp, res, targetSum, 0);

	return res;
}

void process(TreeNode* root, unordered_map<int, int> mp, int &res, int &targetSum, int preSum){
	if(root == nullptr)
		return;
	int cur = root->val + preSum;
	res += mp[cur - targetSum];
	mp[cur]++;
	process(root->left, mp, res, targetSum, cur);
	process(root->right, mp, res, targetSum, cur);
	mp[cur]--;
}

int main(){

	unordered_map<int, int>mp;
	cout<< mp.count(1)<< endl;

}

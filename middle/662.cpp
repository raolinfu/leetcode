#include<unordered_map>
#include<climits>
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
int widthOfBinaryTree(TreeNode* root) {
	inOrderTree(root, 0, 1);
		if(mp.empty())
			return 0;
		unsigned long long res = 0;
		for(auto [k, v]: mp){
			res = max(res, v.second - v.first + 1);
		}

		return res;
    }

	void inOrderTree(TreeNode* root, int deep, unsigned long long idx){
		if(root == nullptr)
			return;
		inOrderTree(root->left, deep + 1, idx * 2);
		if(mp.count(deep)){
			mp[deep].second = idx;
		}
		else{
			mp[deep] = {idx, idx};
		}

		inOrderTree(root->right, deep + 1, idx * 2 + 1);
	}
private:
	unordered_map<int, pair<unsigned long long, unsigned long long>> mp;
};

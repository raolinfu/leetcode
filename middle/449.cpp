#include<string>
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		string str;
		if(root == nullptr)
			return str;
		preOrder(root, str);
		return str;
    }
	void preOrder(TreeNode* root, string& str){
		if(root == nullptr){
			return;
		}
		str += std::to_string(root->val);
		str += '!';
		preOrder(root->left, str);
		preOrder(root->right, str);
	}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		if(data.length() == 0)
			return nullptr;
		vector<int> nums;
		string str;
		for(auto ch: data){
			if(ch == '!'){
				nums.push_back(std::atoi(str.c_str()));	
				str.clear();
			}else{
				str += ch;
			}
		}
		return buildTree(nums, 0, nums.size() - 1);
    }

	TreeNode* buildTree(vector<int>& nums, int i, int j){
		if(i == j)
			return new TreeNode(nums[i]);

		TreeNode* root = new TreeNode(nums[i]);
		int idx = i + 1;
		// 分界点
		while(idx <= j && nums[idx] < nums[i]){
			idx++;
		}
		if(i + 1 <= idx - 1)
			root->left = buildTree(nums, i + 1, idx - 1);
		if(idx <= j)
			root->right = buildTree(nums, idx, j);

		return root;
	}
};

int main(){
	TreeNode* root = new TreeNode(12);
	root->left = new TreeNode(7);
	root->right = new TreeNode(17);
	Codec cod;
	cod.serialize(root);
	

	return 0;
}

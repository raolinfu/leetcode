
#include<vector>
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		return helper(preorder, 0, preorder.size() - 1);
    }
	TreeNode* helper(vector<int>& preorder, int i, int j){
		if(i > j)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[i]);
		if(i == j)
			return root;
		int mid = getLeftGreater(preorder, i + 1, j, preorder[i]);

		root->left = helper(preorder, i + 1, mid - 1);
		root->right = helper(preorder, mid, j);
		return root;
	}
	int getLeftGreater(vector<int>& preorder, int i, int j, int tar){
		int mid;
		int left = i;
		int right = j;
		while(left <= right){
			mid = left + (right - left) / 2;
			if(preorder[mid] > tar){
				right = mid - 1;
			}else if(preorder[mid] < tar){
				left = mid + 1;
			}
		}
		// 都比tar小
		/* if(left == j + 1)
		 *     return -1; */

		return left;
	}
};

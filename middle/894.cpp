#include <vector>
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
    vector<TreeNode*> allPossibleFBT(int n) {
		if (n % 2 == 0)
			return {};
		if (n == 1) {
			TreeNode* n = new TreeNode();
			return {n};
		}
		vector<TreeNode*> ans;
		for (int i = 0; i * 2 + 1 < n; i++) {
			int left_n = i * 2 + 1;
			int right_n = n - 2 * (i + 1);
			auto left = allPossibleFBT(left_n);
			auto right = allPossibleFBT(right_n);
			for (auto l: left) {
				for (auto r: right) {
					TreeNode* cur = new TreeNode();
					cur->left = l;
					cur->right = r;
					ans.push_back(cur);
				}
			}
		}

		return ans;
    }
};

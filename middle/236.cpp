#include<unordered_map>
#include<unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		unordered_set<TreeNode*> set1;
		unordered_set<TreeNode*> set2;
		mp[root] = root;
		traveler(root);
		set1.insert(p);
		set2.insert(q);
		while(true){
			TreeNode* parent1 = mp[p];
			if(set2.count(parent1)){
				return parent1;
			}
			set1.insert(parent1);

			TreeNode* parent2 = mp[q];
			if(set1.count(parent2)){
				return parent2;
			}
			set2.insert(parent2);

			p = parent1;
			q = parent2;
		}
    }

	void traveler(TreeNode* root){
		if(root->left){
			mp[root->left] = root;
			traveler(root->left);
		}

		if(root->right){
			mp[root->right] = root;
			traveler(root->right);
		}
	}
private:
	unordered_map<TreeNode*, TreeNode*> mp;
};

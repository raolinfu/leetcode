#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* t, string& s)    //带空节点的前序遍历
    {
        if (t == nullptr)
        {
            s += 'x';                   //若节点为空，则用x表示，任何其他字母也行
            return;
        }

        s += t->val + '0';
        dfs(t->left, s);
        dfs(t->right, s);
    }

    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        string s1 = "", s2 = "";

        dfs(t1, s1), dfs(t2, s2);       //构造代表两棵树的字符串

        if (s1.find(s2) != string::npos)//判断 s1 是否包含 s2
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};



#include<vector>
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


int process(unordered_map<int, int> &map, int &maxCnt, TreeNode *root);
vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> res;
    unordered_map<int, int> map;
    int maxCnt = 0;
     
    process(map, maxCnt, root);
    for(auto iter = map.begin(); iter != map.end(); iter++){
        if(iter->second == maxCnt)
            res.push_back(iter->first);
    }

    return res;
}

int process(unordered_map<int, int> &map, int &maxCnt, TreeNode *root){
    if(root == nullptr)
        return 0;
    int sum = root->val;
    sum += process(map, maxCnt, root->left);
    sum += process(map, maxCnt, root->right);
    map[sum]++;
    cout<< sum<< endl;
    maxCnt = max(maxCnt, map[sum]);
    return sum;
}
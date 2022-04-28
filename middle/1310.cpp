#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;
        vector<int> pre;
        int c = 0;
        for (int i = 0; i < n; i++) {
            c = c ^ arr[i];
            pre.push_back(c);
        }
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] > 0) {
                int a = queries[i][0] - 1;
                int b = queries[i][1];
                ans.push_back(pre[a] ^ pre[b]);
            } else {
                ans.push_back(pre[queries[i][1]]);
            }
        }

        return ans;
    }
};
int main() {
    vector<int>arr = {1,3,4,8};
    vector<vector<int>>queries = {{0,1},{1,2},{0,3},{3,3}};
    Solution sol;
    auto res = sol.xorQueries(arr, queries);
    for (auto n: res)
        cout<< n<< endl;
    return 0;
}

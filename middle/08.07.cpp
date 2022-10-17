#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<string> res;
    int n;
public:
    vector<string> permutation(string S) {
        n = S.length();
        vector<bool> visited(n, false);
        string tmp;
        dfs(S, tmp, visited, 0);

        return res;
    }

    void dfs(string& s, string& tmp, vector<bool>& visited, int cnt) {
        if (cnt == n) {
            res.emplace_back(tmp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            tmp.push_back(s[i]);
            dfs(s, tmp, visited, cnt + 1);
            tmp.pop_back();
            visited[i] = false;
        }
    }
};
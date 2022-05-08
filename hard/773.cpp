#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
private:
    int getIdx(string& str) {
        int ans;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0') {
                ans = i;
                break;
            }
        }
        return ans;
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string source;
        for (auto& b: board) {
            for (auto &n: b) {
                source += (n + '0');
            }
        }
        // cout<< "source:"<< source<< endl;
        int ans = 0;
        vector<vector<int>> ad{{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        unordered_set<string> st;
        queue<string> que;
        que.push(source);
        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                auto str = que.front();
                if (str == target) {
                    return ans;
                }

                int j = getIdx(str);
                for (auto k: ad[j]) {
                    std::swap(str[k], str[j]);
                    if (!st.count(str)) {
                        st.insert(str);
                        que.push(str);
                    }
                    std::swap(str[k], str[j]);
                }

                que.pop();
            }

            ans++;
        }

        return -1;
    }
};

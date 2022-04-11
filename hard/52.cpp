#include <vector>
#include <cmath>
using namespace std;
class Solution {
private:
    int ans = 0;
public:
    int totalNQueens(int n) {
        vector<pair<int, int>> visit(n);
        backtrace(visit, 0);
        return ans;
    }

    void backtrace(vector<pair<int, int>>& visit, int idx) {
        if (idx == visit.size()) {
            ans++;
            return;
        }

        for (int j = 0; j < visit.size(); j++) {
            visit[idx] = {idx, j};
            if (isValid(visit, idx)) {
                backtrace(visit, idx + 1);
            }
        }

    }

    bool isValid(vector<pair<int, int>>& visit, int idx) {
        for (int i = 0; i < idx; i++) {
            if (visit[i].second == visit[idx].second)
                return false;
            if (abs(visit[idx].first - visit[i].first) == abs(visit[idx].second - visit[i].second))
                return false;
        }

        return true;
    }
};

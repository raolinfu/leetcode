#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx > tx || sy > ty)
            return false;

        queue<pair<int, int>> que;
        que.push({sx, sy});
        while (!que.empty()) {
            auto f = que.front();
            que.pop();
            if (f.first == tx && f.second == ty)
                return true;
            int x1 = f.first + f.second;
            int y1 = f.second;
            if (x1 <= tx) {
                que.push({x1, y1});
            }
            int x2 = f.first;
            int y2 = f.first + f.second;
            if (y2 <= ty)
                que.push({x2, y2});
        }

        return false;
    }
};

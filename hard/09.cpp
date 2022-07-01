#include <vector>
using namespace std;

class Solution {
private:
    int f[10000000 + 7];
    int maxdis[10000000 + 7];
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        int w = 0;
        int ans = 1000000000;

        for (int i=1; i<=n; ++i) {
            f[i] = 1000000000;
            maxdis[i] = 0;
        }
        f[1] = 0;
        maxdis[0] = 1;

        for (int i=1; i<=n; ++i) {
            if (i > maxdis[w]) { // 更新单调指针
                ++w;
            }
            f[i] = min(f[i], w+1); // 用 maxdis[w] 更新 f[i]
            int next = i + jump[i-1]; // 第一步跳跃更新

            if (next > n) {
                ans = min(ans, f[i] + 1);
            } else if (f[next] > f[i] + 1) {
                f[next] = f[i] + 1;
                maxdis[f[next]] = max(maxdis[f[next]], next);
            }
        }

        return ans;
    }
};

class Solution1 {
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();

        queue< pair<int, int> > q; // 当前位置 idx，按动次数 d
        // 初始值：编号为 0 的弹簧  按动次数 为0
        q.emplace(0, 0);

        // 某一个位置已经被扩展过了，就不需要被再次扩展：BFS最短路
        // 记录某个位置是否被扩展过：seen
        vector<bool> seen(n, false);
        seen[0] = true;


        int preidx = 1;
        // BFS
        while(!q.empty()) {
            auto [idx, d] = q.front();
            q.pop();

            // 向右扩展
            int next = idx + jump[idx];
            if(next > n - 1) {
                // 跳出弹簧
                // BFS 最短路
                return d + 1;
            }
            if(!seen[next]) {
                seen[next] = true;
                q.emplace(next, d + 1);
            }

            // 向左扩展：O(n^2)
            // 某一个位置及其之前所有位置都已经被扩展过，那么一定是最短路，不需要再次被扩展
            // preidx：记录某个位置及其之前位置均已被扩展，每次更新preidx 即可
            // for(int i = 0; i < idx; i++) {
            //     if(!seen[i]) {
            //         seen[i] = true;
            //         q.emplace(i, d + 1);
            //     }
            // }

            while(preidx < idx) {
                // 最多只会遍历一遍全部位置 ：O(n)
                if(!seen[preidx]) {
                    seen[preidx] = true;
                    q.emplace(preidx, d + 1);
                }
                preidx++;
            }
        }

        // 遍历完整个队列，还未返回，说明无法到达
        return -1;

    }
};


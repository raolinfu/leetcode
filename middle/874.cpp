#include <vector>
#include <unordered_set>
#include <utility>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;

        unordered_set<pair<int, int>, pair_hash> obstacleSet;
        for (vector<int> obstacle: obstacles)
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));

        int ans = 0;
        for (int cmd: commands) {
            if (cmd == -2)
                di = (di + 3) % 4;
            else if (cmd == -1)
                di = (di + 1) % 4;
            else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
					// 这个点不是阻碍点
                    if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x*x + y*y);
					// 遇到阻碍点就停止，看下一条指令
                    } else {
						break;
					}
					
                }
            }
        }

        return ans;
    }
private:
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);
    
            return h1 ^ h2;
        }
    };
};


/* class Solution {
 * public:
 *     int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
 *         int ans = 0;
 *         unordered_map<int, vector<int>> xNums;
 *         unordered_map<int, vector<int>> yNums;
 *         for (auto v: obstacles) {
 *             if (xNums.count(v[0])) {
 *                 xNums[v[0]].push_back(v[1]);
 *             }
 *             else {
 *                 xNums[v[0]] = vector<int>(v[1]);
 *             }
 *
 *             if (yNums.count(v[1])) {
 *                 yNums[v[1]].push_back(v[0]);
 *             }
 *             else {
 *                 yNums[v[1]] = vector<int>(v[0]);
 *             }
 *         }
 *         for (auto [k, v]: xNums) {
 *             sort(v.begin(), v.end());
 *         }
 *         for (auto [k, v]: yNums) {
 *             sort(v.begin(), v.end());
 *         }
 *
 *         return ans;
 *     }
 *
 *     int getBound(vector<int>& nums, int a, int b) {
 *         auto iter = std::upper_bound(nums.begin(), nums.end(), a);
 *         if (iter == nums.end())
 *             return INT_MAX;
 *         else
 *             return *iter;
 *     }
 * }; */
int main() {

	return 0;
}

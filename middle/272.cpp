#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int rangeLeft = 0, rangeRight = INT_MAX;
        int size = nums.size();
		// 每行的指针
        vector<int> next(size);
        
        auto cmp = [&](const int& u, const int& v) {
            return nums[u][next[u]] > nums[v][next[v]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int minValue = 0, maxValue = INT_MIN;
        for (int i = 0; i < size; ++i) {
            pq.emplace(i);
            maxValue = max(maxValue, nums[i][0]);
        }

        while (true) {
			// 保存的是行
            int row = pq.top();
            pq.pop();
            minValue = nums[row][next[row]];
            if (maxValue - minValue < rangeRight - rangeLeft) {
                rangeLeft = minValue;
                rangeRight = maxValue;
            }
            if (next[row] == nums[row].size() - 1) {
                break;
            }
			// 行的下一个指针
            ++next[row];
            maxValue = max(maxValue, nums[row][next[row]]);
            pq.emplace(row);
        }

        return {rangeLeft, rangeRight};
    }
};


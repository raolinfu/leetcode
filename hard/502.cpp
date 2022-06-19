#include <type_traits>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// 在capital满足情况下 每次拿利润最大的
// n > capital  push, 最后pop

struct Cmp {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> nums;
        for (int i = 0; i < profits.size(); i++)
            nums.push_back({profits[i], capital[i]});
        std::sort(nums.begin(), nums.end(), [](const auto& a, const auto& b) {
                return a.second < b.second;
                });
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> priq;

        int i = 0;
        while (i < nums.size()) {
            while (k && !priq.empty() && w < nums[i].second) {
                w += priq.top().first;
                priq.pop();
                k--;
            }

            if (w < nums[i].second)
                break;

            while (i < nums.size() && w >= nums[i].second) {
                priq.push(nums[i]);
                i++;
            }

            if (!priq.empty() && k) {
                w += priq.top().first;
                priq.pop();
                k--;
            }

            if (k == 0)
                break;
        }

        while (k && !priq.empty()) {
            w += priq.top().first;
            priq.pop();
            k--;
        }

        return w;
    }
};

int main() {

    return 0;
}

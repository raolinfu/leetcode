#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> P(n+1);

        for (int i = 0; i < n; ++i)
            P[i+1] = P[i] + (long) nums[i];

        // Want smallest y-x with P[y] - P[x] >= k
        int ans = n+1; // n+1 is impossible
        deque<int> monoq;//opt(y) candidates, as indices of P

        for (int y = 0; y < P.size(); ++y) {
            // Want opt(y) = largest x with P[x] <= P[y] - k;
            while (!monoq.empty() && P[y] <= P[monoq.back()])
                monoq.pop_back();
            while (!monoq.empty() && P[y] >= P[monoq.front()] + k) {
                int front = monoq.front();
                ans = min(ans, y - front);
                monoq.pop_front();
            }

            monoq.push_back(y);
        }

        return ans < n+1 ? ans : -1;
    }
};

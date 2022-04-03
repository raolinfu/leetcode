#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        queue<int> q;
        for (auto n: nums)
            q.push(n);

        while (q.size() > 1) {
            int len = q.size();
            for (int i = 0; i < len - 1; i++) {
                int front = q.front();
                q.pop();
                int tmp = (front + q.front()) % 10;
                q.push(tmp);
                if (i == len - 2) {
                    q.pop();
                }
            }
        }
        
        return q.front();
    }
};

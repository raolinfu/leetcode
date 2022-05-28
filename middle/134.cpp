#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int spare = 0;
        int len = gas.size();
        int minNum = INT_MAX;
        int ans;
        for (int i = 0; i < gas.size(); i++) {
            spare += gas[i] - cost[i];
            if (minNum > spare) {
                minNum = spare;
                ans = i;
            }
        }

        return spare >= 0? (ans + 1) % len: -1;
    }
};

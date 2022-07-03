#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = pow(10, 9) + 7;
        int ans = 0;
        vector<int> dp(forget + 1, 0);

        dp[1] = 1;

        for (int i = 0; i < n - 1; i++) {
            int s = 0;
            for (int j = delay; j < forget; j++) {
                s = (s + dp[j]) % mod;
            }

            for (int j = forget; j > 1; j--) {
                dp[j] = dp[j - 1];
            }

            dp[1] = s;
        }

        for (int i = 1; i <= forget; i++) {
            ans = (ans + dp[i]) % mod;
        }

       return ans; 
    }
};

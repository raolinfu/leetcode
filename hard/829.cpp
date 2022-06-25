/* 
 * a * (a + k) * k= 2 * n
 * */
#include <cmath>
using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        n = 2 * n;
        for (int i = 1; i * i < n; i++) {
            if (n % (i + 1) == 0) {
                int l = 0;
                int r = n / 2;
                while (l <= r) {
                    int k = (r + l) / 2;
                    int num = (2 * k + i) * (i + 1);
                    if (num == n && k != 0) {
                        ans++;
                        break;
                    } else if (num > n) {
                        r = k - 1;
                    } else {
                        l = k + 1;
                    }
                }

                /* for (int k = 1; (2 * k + i) * (i + 1) <= n; k ++) {
                 *     if ((2 * k + i) * (i + 1) == n) {
                 *         ans++;
                 *         break;
                 *     }
                 * } */
            }
        }

        return ans;
    }
};

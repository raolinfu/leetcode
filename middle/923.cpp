#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int MOD = pow(10, 9) + 7;
        long ans = 0;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size() - 1; ++i) {
            // We'll try to find the number of i < j < k
            // with A[j] + A[k] == T, where T = target - A[i].

            // The below is a "two sum with multiplicity".
            int T = target - arr[i];
            int j = i+1, k = arr.size() - 1;

            while (j < k) {
                // These steps proceed as in a typical two-sum.
                if (arr[j] + arr[k] < T)
                    j++;
                else if (arr[j] + arr[k] > T)
                    k--;
                else if (arr[j] != arr[k]) {  // We have A[j] + A[k] == T.
                    // Let's count "left": the number of A[j] == A[j+1] == A[j+2] == ...
                    // And similarly for "right".
                    int left = 1, right = 1;
                    while (j+1 < k && arr[j] == arr[j+1]) {
                        left++;
                        j++;
                    }
                    while (k-1 > j && arr[k] == arr[k-1]) {
                        right++;
                        k--;
                    }

                    ans += left * right;
                    ans %= MOD;
                    j++;
                    k--;
                } else {
                    // M = k - j + 1
                    // We contributed M * (M-1) / 2 pairs.
                    ans += (k-j+1) * (k-j) / 2;
                    ans %= MOD;
                    break;
                }
            }
        }

        return (int) ans;
    }
};

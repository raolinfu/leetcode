#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            int maxH = 0;
            int width = 0;
            for (int j = i; j >= 1; j--) {
                width += books[j - 1][0];
                maxH = max(maxH, books[j - 1][1]);
                if (width <= shelfWidth) {
                    dp[i] = min(dp[i], dp[j - 1] + maxH);
                    continue;
                }
                break;
            }
        }

        return dp[n];
    }
};

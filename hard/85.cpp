#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        stack<int> stk;

        for (int j = 0; j < cols; j++)
            dp[0][j] = matrix[0][j] == '1';
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    dp[i][j] = dp[i - 1][j] + 1;
            }
        }
        stk.push(-1);
        for (int i = 0; i < rows; i++) {
            int j = 0;
            while (j < cols) {
                while (stk.size() > 1 && dp[i][stk.top()] > dp[i][j]) {
                    int top = stk.top(); 
                    stk.pop();
                    int len = j - stk.top() - 1;
                    ans = max(ans, len * dp[i][top]);
                }

                j++;
            }
            while (stk.size() > 1) {
                int top = stk.top(); 
                stk.pop();
                int len = cols - stk.top() - 1;
                ans = max(ans, len * dp[i][top]);
            }
        }

        return ans;
    }
};

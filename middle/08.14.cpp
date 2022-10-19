#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countEval(string s, int result) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int i=0; i<n; i+=2){
            int tmp = 0;
            if (s[i] == '1') 
                tmp = 1;
            dp[i][i][0] = 1-tmp;
            dp[i][i][1] = tmp;
        }

        for (int step=0; step<n; step+=2){
            for (int i=0; i+step<n; i+=2){
                for (int j=i+1; j<i+step; j+=2){
                    int left0 = dp[i][j-1][0], left1 = dp[i][j-1][1];
                    int right0 = dp[j+1][i+step][0], right1 = dp[j+1][i+step][1];
                    if (s[j]=='&'){
                        dp[i][i+step][0] += left0*(right0+right1)+left1*right0;
                        dp[i][i+step][1] += left1*right1;
                    }
                    else if (s[j]=='|'){
                        dp[i][i+step][0] += left0*right0;
                        dp[i][i+step][1] += left0*right1 + left1*(right0+right1);
                    }
                    else{//s[j]=='^'
                        dp[i][i+step][0] += left0*right0 + left1*right1;
                        dp[i][i+step][1] += left0*right1 + left1*right0;
                    }
                }
            }
        }
        return dp[0][n-1][result];
    }
};


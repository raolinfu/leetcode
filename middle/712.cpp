#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int a = s1.size();
        int b = s2.size();
        vector<vector<int>> dp (a+1, vector<int> (b+1,0));

        for(int i = a-1;i>=0;i--){
            dp[i][b] = dp[i+1][b] + s1[i];
        }

        for(int j = b-1;j>=0;j--){
            dp[a][j] = dp[a][j+1] + s2[j];
        }

        for(int i = a-1;i>=0;i--){
            for(int j = b-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    dp[i][j] = min(int(s1[i])+dp[i+1][j], int(s2[j])+dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
    }

};


#include<vector>
#include<iostream>
using namespace std;

int change(int amount, vector<int>& coins) {
    int rows = coins.size();
    int cols = amount;
    vector<vector<int>> dp(rows, vector<int>(cols + 1, 0));
    for(int i = 0; i < rows; i++)
        dp[i][0] = 1;
    for(int j = 1; j <= cols; j++){
        if(j % coins[0] == 0)
            dp[0][j] = 1;
        else
            dp[0][j] = 0;
    }

    for(int i = 1; i < rows; i++){
        for(int j = 1; j <= cols; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - coins[i] >= 0)
                dp[i][j] += dp[i][j - coins[i]];
        }
    }

    return dp[rows - 1][amount];
}
int main(int argc, char const *argv[])
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    int ans = change(amount, coins);
    cout<< ans<< endl;
    return 0;
}

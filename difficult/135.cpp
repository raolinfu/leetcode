#include<vector>
using namespace std;


int candy(vector<int>& ratings) {
	if(ratings.size() == 0)
		return 0;
	if(ratings.size() == 1)
		return 1;
	int res;
	vector<int> dp(ratings.size());
	dp[0] = ratings[0] > ratings[1]? 2: 1;
	for(int i = 1; i < ratings.size(); i++){
		if(dp[i])	

	}


	return res;
}

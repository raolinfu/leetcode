#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
	map<int, int> mp;
	sort(nums.begin(), nums.end());
	for(auto n: nums)
		mp[n]++;
	
	vector<int> dp(mp.size());
	int i = 0;
	for(auto iter = mp.begin(); iter != mp.end(); iter++){
		if(i == 0){
			dp[i] = iter->first * iter->second; 
			i++;
			continue;
		}

		if(mp.count(iter->first - 1)){
			if(i - 2 >= 0)
				dp[i] = max(dp[i - 1], dp[i - 2] + iter->first * iter->second);
			else
				dp[i] = max(dp[i - 1], iter->first * iter->second);
		}else{
			dp[i] = dp[i - 1] + iter->first * iter->second;
		}

		i++;
	}

	return *dp.rbegin();
}

int main(){
	vector<int>nums = {2,2,3,3,3,4};
	int res = deleteAndEarn(nums);
	cout<< res<< endl;

	return 0;
}

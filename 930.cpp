#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
	int ans = 0;
	int sum = 0;
	unordered_map<int, int> map;
	map[sum] = 1;
	for(auto ele: nums){
		sum += ele;
		if(map.count(sum - goal)){
			ans += map[sum - goal];
		}
		map[sum]++;
	}

	return ans;
}
int main(){
	/* vector<int>nums = {1,0,1,0,1};
	 * int goal = 2; */
	vector<int>nums = {0,0,0,0,0};
	int goal = 0;
	int ans = numSubarraysWithSum(nums, goal);
	cout<< ans<< endl;
	return 0;
}

#include<vector>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
	int b = 0;
	int e = -1;
	int sum = 0;
	int res = INT_MAX;
	int len = nums.size();
	while(e < len && b < len){
		if(sum < target){ 
			e++;
			sum += nums[e];
		}
		else if(sum > target){
			sum -= nums[b];
			b++;
		}

		if(sum == target){
			res = min(res, e - b + 1);
			sum -= nums[b];
			b++;
		}
	}

	return res == INT_MAX? 0: res;
}
int main(){
	int target =11;
	vector<int> nums = {1,1,1,1,1,1,1,1};
	//int target =4;
	//vector<int> nums = {1,4,4};
	//int target =7;
	//vector<int> nums = {2,3,1,2,4,3};
	int res = minSubArrayLen(target, nums);
	cout<< res<< endl;
	return 0;
}

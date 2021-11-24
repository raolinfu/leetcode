#include<vector>
#include<climits>
#include<iostream>
using namespace std;

int partitionDisjoint(vector<int>& nums) {
	int res = 0;
	int maxNum = INT_MIN;
	int minNum = INT_MAX;
	vector<int> left(nums.size());
	vector<int> right(nums.size());
	for(int i = 0; i < nums.size(); i++){
		maxNum = max(nums[i], maxNum);
		left[i] = maxNum;
	}
	for(int i = nums.size() - 1; i >=0; i--){
		right[i] = minNum;
		minNum = min(minNum, nums[i]);
	}
	for(int i = 0; i < nums.size(); i++){
		if(left[i] <= right[i]){
			return i + 1;
		}
	}

	return nums.size();
}

int main(){
	// vector<int> nums = {5,0,3,8,6};
	vector<int> nums = {1,1,1,0,6,12};
	int res = partitionDisjoint(nums);
	cout<< res<< endl;
	return 0;
}

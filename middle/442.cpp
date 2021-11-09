#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
// 将数组的下标存储值
vector<int> findDuplicates(vector<int>& nums) {
	vector<int> res;
	for(int i = 0; i < res.size(); i++){
		if(i && nums[abs(nums[i]) - 1] < 0){
			res.push_back(abs(nums[i]));
		}else{
			nums[abs(nums[i]) - 1] = -nums[nums[i]];
		}
	}

	return res;
}

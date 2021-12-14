#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
int wiggleMaxLength(vector<int>& nums) {
	if(nums.size() == 1 || (nums.size() == 0 && nums[0] != nums[1]))
		return nums.size();
	int res = 0;
	vector<int> up(nums.size()); 
	vector<int> down(nums.size()); 

	return res;
}

int main(){
	vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
	int res = wiggleMaxLength(nums);
	cout<< res<< endl;
	return 0;
}

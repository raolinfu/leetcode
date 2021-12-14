#include<vector>
#include<climits>
#include<iostream>
using namespace std;
// 有一次递减 flag = 1 递减后有立刻增了 flag = 2
bool checkPossibility(vector<int>& nums) {
	int flag = 0;
	int pre = nums[0];
	int cmp = INT_MIN;
	for(int i = 1; i < nums.size(); i++){
		if(!flag){
			if(nums[i] < pre){
				flag = 1;
				cmp = i - 2 >= 0? nums[i - 2]: INT_MIN;
			}
		}else if(flag == 1){
			if(nums[i] <= pre || nums[i] < cmp)
				return false;
			flag = 2;
		}else if(flag == 2){
			if(nums[i] < pre)
				return false;
		}
		pre = nums[i];
	}
	return true;
}
int main(){
	vector<int>nums = {4,2,3};
	int res = checkPossibility(nums);
	cout<< res<< endl;
	return 0;
}

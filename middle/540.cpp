#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
	int pre = nums[0];
	int cnt = 1;
	for(int i = 1; i < nums.size(); i++){
		if(nums[i] == pre)
			cnt++;
		else if(cnt == 1){
			return pre;
		}else{
			pre = nums[i];
			cnt = 1;
		}
	}

	return pre;
}

int main(){
	vector<int>nums = {1,1,2,2,3,3,4,4,8,8,9};
	int res = singleNonDuplicate(nums);
	cout<< res<< endl;
	return 0;
}

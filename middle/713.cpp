#include<vector>
#include<iostream>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	int res = 0;
	int ans = 1;
	int left = 0;
	int right = 0;
	if(k == 0)
		return 0;

	while(left <= right && right < nums.size()){
		ans *= nums[right];
		if(ans < k){
			res += right - left + 1;
			right++;
		}else{
			// 这里要判断left <= right
			while(ans >= k && left <= right){
				ans /= nums[left];
				left++;
			}
			if(left <= right)
				res += right - left + 1;
			right++;
		}
	}

	return res;
}

int main(){
	/* vector<int>nums = {10,5,2,6};
	 * int k = 100; */
	vector<int> nums = {1,1,1};
	int k = 1;
	int res = numSubarrayProductLessThanK(nums, k);
	cout<< res<< endl;
	return 0;
}

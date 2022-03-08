#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int findPeakElement(vector<int> nums){
	if(nums.size() == 1)
		return 0;
	if(nums[0] > nums[1])
		return 0;
	else if(nums[nums.size() - 1] > nums[nums.size() - 2])
		return nums.size() - 1;
	int l = 1;
	int r = nums.size() - 2;
	int m;

	while(l <= r){
		m = l + (r - l) / 2;
		if(l != r){
			if((nums[m] - nums[m - 1]) > 0 &&  (nums[m] - nums[m + 1]) > 0)
				return m;
			else if(nums[m + 1] - nums[m - 1] > 0){
				l = m + 1;
			}else{
				r = m - 1;
			}

		}
		else 
			return m;
	}

	return l;
} 
int main(){
	vector<int> nums = {1,2,1,3,5,6,4};
	auto ans = findPeakElement(nums);
	cout<< ans<< endl;
	return 0;
}

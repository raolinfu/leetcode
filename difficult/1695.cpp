#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
int maximumUniqueSubarray(vector<int>& nums) {
	int sum = 0;
	int ans = 0;
	int left = 0;
	int right = 0;
	unordered_map<int, int> map;
	while(left <= right && right < nums.size()){
		if(map[nums[right]] == 0){
			map[nums[right]] = 1;
			sum += nums[right];
			right++;
		}else{
			map[nums[right]]++;
			sum += nums[right];
			while(map[nums[right]] == 2){
				if(nums[left] == nums[right]){
					map[nums[right]]--;
					sum -= nums[left];
					right++;
					left++;
					break;
				}
				sum -= nums[left];
				left++;
			}
		}
		ans = max(ans, sum);
	}

	return ans;
}
int main(){
	// vector<int> nums = {4,2,4,5,6};
	vector<int>nums = {5,2,1,2,5,2,1,2,5};
	int ans = maximumUniqueSubarray(nums);
	cout<< ans<< endl;

	return 0;
}

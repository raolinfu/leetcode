#include<vector>
#include<iostream>
using namespace std;
int main(){
	vector<int> nums = {2, 4, 4, 5, 5, 7};
	int n = 5;
	int ans = -1;
	int left = 0;
	/* int right = nums.size() - 1;
	 * while(left <= right){
	 *     int middle = left + (right - left) / 2;
	 *     if(nums[middle] == n){
	 *         right = middle - 1;
	 *     }
	 *     else if(nums[middle] > n){
	 *         right = middle - 1;
	 *     }
	 *     else if(nums[middle] < n){
	 *         left = middle + 1;
	 *     }
	 * }
	 * if(left == nums.size() || nums[left] != n)
	 *     cout<< -1<< endl;
	 * else
	 *     cout<< left<< endl; */

	int right = nums.size();
	while(left < right){
		int middle = left + (right - left) / 2;
		if(nums[middle] == n){
			right = middle;
		}
		else if(nums[middle] > n){
			right = middle;
		}
		else if(nums[middle] < n){
			left = middle + 1;
		}
	}
	if(left == nums.size() || nums[left] != n)
		cout<< -1<< endl;
	else
		cout<< left<< endl;
	return 0;
}

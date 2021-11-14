#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
	int res = 0;
	int sum = 0;
	int len = nums.size();
	unordered_multiset<int> set;
	set.insert(0);
	for(int i = 0; i < len; i++){
		sum += nums[i];
		res += set.count(sum - k);	
		set.insert(sum);
	}

	return res;
}

int main(){
	/* vector<int>nums = {1,1,1};
	 * int k = 2; */
	vector<int>nums = {1,2,3};
	int k = 3;
	int res = subarraySum(nums, k);
	cout<< res<< endl;
	return 0;
}

#include<vector>
#include<unordered_set>
#include<iostream>
#include<unordered_map>
using namespace std;
bool checkSubarraySum(vector<int>& nums, int k) {
	long sum = 0;
	unordered_map<int, int> set;
	set.insert(0, -1);
	for(int i = 0; i < nums.size(); i++){
		sum += nums[i];
		cout<< i<<"\t" << sum % k<< endl;
		if(!set.count(sum % k)){
			set.insert({sum % k, i});
			continue;
		}
		if(i > 0 && sum >= k)
			return true;	
	}

	return false;
}

int main(){
	vector<int>nums = {23,2,4,6,7};
	int k = 6;
	/* vector<int>nums = {23,2,6,4,7};
	 * int k = 6; */
	/* vector<int>nums = {23,2,6,4,7};
	 * int k = 13; */
	int res = checkSubarraySum(nums, k);
	cout<< res<< endl;
	return 0;
}

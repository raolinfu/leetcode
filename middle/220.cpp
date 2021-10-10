#include<vector>
#include<cmath>
#include<unordered_map>
#include<climits>
using namespace std;

// hash算法 空间复杂度为o(n)
vector<int> majorityElement(vector<int>& nums) {
	vector<int> res;
	unordered_map<int, int> mp;
	for(int i = 0; i < nums.size(); i++){
		if(mp.find(nums[i]) == mp.end()){
			mp.insert({nums[i], 1});
		}else if(mp[nums[i] > floor(nums.size() / 3)]){
			res.push_back(nums[i]);
			mp[nums[i]] = INT_MIN;
		}
		else{
			mp[nums[i]]++;
		}	
	};   
	return res;
}

// 摩尔投票法
vector<int> majorityElement1(vector<int>& nums) {
	vector<int> res;
	int candidate1 = nums[0];
	int candidate2 = nums[0];
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] == candidate1){
			cnt1++;
			continue;
		}
	
		if(nums[i] == candidate2){
			cnt2++;
			continue;
		}

		if(cnt1 == 0){
			candidate1 = nums[i];
			cnt1++;
			continue;
		}

		if(cnt2 == 0){
			candidate2 = nums[i];
			cnt2++;
			continue;
		}
		cnt1--;
		cnt2--;
	}
	cnt1 = 0;
	cnt2 = 0;
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] == candidate1){
			cnt1++;
		}else if(nums[i] == candidate2){
			cnt2++;
		}	
	}
	if(cnt1 > nums.size() / 3)
		res.push_back(candidate1);
	if(cnt2 > nums.size() / 3)
		res.push_back(candidate2);

	return res;
}

int main(){
	vector<int> nums ={1,1,1,3,3,2,2,2};
	vector<int> res = majorityElement1(nums);

	return 0;
}

#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
	int ans = 0;
	int sum = 0;
	int len = nums.size();
	unordered_map<int, int> map;
	vector<int> dp(len);
	map.insert({0, 1});
	for(int i = 0; i < len; i++){
		sum += nums[i];
		int cmp = sum % k;
		ans += map[cmp];
		// 有负数 需要看 k = 6 4 -2 	-2 4
		ans += map[cmp - k];
		ans += map[cmp + k];
		map[cmp]++;
	}

	return ans;
}
int main(){
	cout<< -2 % 6<< endl;
	vector<int> A = {-1,2,9};
	int K = 2;
	/* vector<int>A = {4,5,0,-2,-3,1};
	 * int K = 5; */
	int ans = subarraysDivByK(A, K);
	cout<< ans<< endl;
	return 0;
}

#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
		int ans = 0;
		int m = 0;
		for(auto n: nums)
			m = max(n, m);
		for(int i = -m; i <= m; i++)
			ans = max(ans, findKmost(nums, i));

		return ans;
    }

	int findKmost(vector<int>& nums, int k){
		unordered_map<int, int> mp;
		int ans = 0;
		for(auto n: nums){
			if(mp.count(n - k)){
				mp[n] = max(mp[n], mp[n - k] + 1);
				ans = max(ans, mp[n]);
			}
			else{
				mp[n] = 1;
			}
		}

		return ans;
	}
};
int main(){

	return 0;
}

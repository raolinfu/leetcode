#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution{
	public:
		bool canPartitionKSubset(vector<int>& nums, int k){
			int sum  = 0;
			for(auto n: nums)
				sum += n;
			if(sum % k != 0)
				return false;
			string s(nums.size(), '0');
			sort(nums.begin(), nums.end());
			int base = sum / k;
			return helper(nums, base, s, k, base ,0);
		}
		bool helper(vector<int>& nums, int target, string used, int &k, int& base, int cnt){
			if(cnt == k)
				return true;
			if(mp.count(used))
				return false;

			for(int i = 0; i < nums.size(); i++){
				if(used[i] == '1'){
					continue;
				}
				else if(used[i] == '0' && nums[i] > target){
					break;
				}
				else if(used[i] == '0' && nums[i] == target){
					string tmp = used;
					tmp[i] = '1';
					if(helper(nums, base, tmp, k, base, cnt + 1))
						return true;
				}
				else if(used[i] == '0' && nums[i] < target){
					string tmp = used;
					tmp[i] = '1';
					if(helper(nums, target - nums[i], tmp, k, base, cnt))
						return true;
				}
			}

			mp[used] = false;
			return false;
		}
	private:
		unordered_map<string, bool> mp;
};

int main(){
	Solution s;
	vector<int> nums{1, 3, 4, 6, 2, 5, 3};
	int k = 4;
	cout<< s.canPartitionKSubset(nums, k)<< endl;

	return 0;
}

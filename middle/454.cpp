#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		int ans = 0;
		unordered_map<int, int> map1;
		unordered_map<int, int> map2;
		for(int i = 0; i < nums1.size(); i++){
			for(int j = 0; j < nums2.size(); j++){
				map1[nums1[i] + nums2[j]]++;
			}
		}

		for(int i = 0; i < nums3.size(); i++){
			for(int j = 0; j < nums4.size(); j++){
				map2[nums3[i] + nums4[j]]++;
			}
		}
		for(auto [k, v]: map1){
			if(map2.count(-k)){
				ans += v * map2[-k];
			}
		}

		return ans;
    }
};
int main(){
	Solution s;
	vector<int>nums1 = {1,2}; 
	vector<int>nums2 = {-2,-1}; 
	vector<int>nums3 = {-1,2}; 
	vector<int>nums4 = {0,2};
	int ans = s.fourSumCount(nums1, nums2, nums3, nums4);
	cout<< ans<< endl;
	return 0;
}

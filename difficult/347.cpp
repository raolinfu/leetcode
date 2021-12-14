#include<iostream>
#include<algorithm>
#include<vector>
/*
 *topK问题
 * */
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
	vector<int> res;
	int i = 0;
	int j = 0;
	swap(nums[i], *nums.rbegin());
	while(i < k){
		if(nums[i] <= *nums.rbegin()){
			i++;
			j++;
		}	

	}
	return res;
}

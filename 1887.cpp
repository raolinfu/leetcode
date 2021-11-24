#include<vector>
#include<climits>
#include<algorithm>
#include<iostream>

using namespace std;
int reductionOperations(vector<int>& nums) {
	int res = 0;
	int pre = INT_MAX;
	sort(nums.begin(), nums.end(), greater<int>());
	if(*nums.begin() == *nums.rbegin())
		return 0;
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] != pre){
			res += i;
			pre = nums[i];
		}
	}	
	for(auto n: nums)
		cout<< n<< endl;
	return res;
}

int main(){
	vector<int> nums = {5,1,3};
	int res = reductionOperations(nums);
	cout<< "-------"<< endl;
	cout<< res<< endl;

	return 0;
}

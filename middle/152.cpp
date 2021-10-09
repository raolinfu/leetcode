#include<vector>
#include<iostream>
#include<climits>
using namespace std;

int maxProduct(vector<int>& nums) {
	int res = INT_MIN;
	int mx = INT_MIN;
	int mi = INT_MAX;
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] > 0){
			mx = mx == INT_MIN? nums[i]: mx * nums[i];
			mi = mi == INT_MAX? mi: mi * nums[i];
		}else if(nums[i] < 0){
			int tmp = mx;
			mx = mi == INT_MAX? INT_MIN: mi * nums[i];
			mi = tmp == INT_MIN? nums[i]: tmp * nums[i];
		}else{
			res = max(res, 0);
			mx = INT_MIN;
			mi = INT_MAX;
		}

		res = mi == INT_MAX? res: max(res, mi);
		res = mx == INT_MIN? res: max(res, mx);
	}

	return res;
}

int main(){
	vector<int> nums = {12, -1, 7, 0, 2, 5};
	int res = maxProduct(nums);
	cout << res << endl;
	return 0;
}


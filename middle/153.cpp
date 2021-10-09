#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int getMin(vector<int> &nums){
	int e = nums.size() - 1;
	int b = 0;
	if(nums[b] < nums[e])
		return nums[0];

	int m;
	while(b < e){
		m = (b + e) / 2;
		if(nums[m] > nums[e])
			b = m + 1;
		else
			e = m;
	}

	return min(nums[b], nums[e]);
}


int main(){
	vector<int> nums = {4, 5, 1, 2, 3};
	cout<< getMin(nums)<< endl;
	
	return 0;

}

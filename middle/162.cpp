#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int findPeakElement(vector<int> nums){
	int b = 0;
	int e = nums.size();
	int m;
	while(b < e){
		m = (b + e) >> 1;
		if(nums[m] > nums[b] && nums[m] > nums[e]){
			if(nums[b] > nums[e]){
				e = m;
			}else{
				b = m;
			}
		}
		else if(nums[m] < nums[b] && nums[m] < nums[e]){
			if(nums[b] > nums[e]){
				e = m - 1;
			}else{
				b = m - 1;
			}
		}else{

		}
	}
} 

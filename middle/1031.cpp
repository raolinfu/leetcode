#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
		int ans = 0;
		int n = nums.size();
		vector<int> left2right(n, 0);
		vector<int> right2left(n, 0);
		ans = max(ans, helper(nums, left2right, right2left, firstLen, secondLen));
		ans = max(ans, helper(nums, left2right, right2left, secondLen, firstLen));
		return ans;
    }
	int helper(vector<int>& nums, vector<int>& left2right, vector<int>& right2left, int firstLen, int secondLen){
		int n = nums.size();
		int ans = 0;
		int left = 0;
		int right = 0;
		int sum = 0;
		int maxSum = 0;
		while(right < n){
			sum += nums[right];
			if(right - left == firstLen - 1){
				maxSum = max(sum, maxSum);
				left2right[right] = maxSum;
				sum -= nums[left];
				left++;
			}
			right++;
		}
		right = n - 1;
		left = n - 1;
		sum = 0;
		maxSum = 0;
		while(left >= 0){
			sum += nums[left];
			if(right - left == secondLen - 1){
				maxSum = max(sum, maxSum);
				right2left[left] = maxSum;
				sum -= nums[right];
				right--;
			}
			left--;
		}
		for(int i = firstLen - 1; i < n - secondLen; i++){
			ans = max(ans, left2right[i] + right2left[i + 1]);
		}
		return ans;
	}
};
int main(){
	vector<int>A = {0,6,5,2,2,5,1,9,4};
	int L = 1;
	int M = 2;
	Solution s;
	int ans = s.maxSumTwoNoOverlap(A, L, M);
	cout<< ans<< endl;
	return 0;
}

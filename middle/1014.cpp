#include<vector>
#include<climits>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
		int ans = INT_MIN;
		int n = values.size();
		vector<int> nums1(n, 0);
		vector<int> nums2(n, 0);

		int maxNum = 0;
		for(int i = 0; i < n; i++){
			maxNum = max(maxNum, values[i] + i);
			nums1[i] = maxNum;
		}

		maxNum = 0;
		for(int i = n - 1; i >= 0; i--){
			maxNum = max(maxNum, values[i] + n - i - 1);
			nums2[i] = maxNum;
		}

		maxNum = 0;
		for(int i = 0; i < n - 1; i++){
			maxNum = max(maxNum, nums1[i] + nums2[i + 1] - n + 1);
			ans = maxNum;
		}

		return ans;
    }
};
int main(){

	return 0;
}

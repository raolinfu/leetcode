#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
	int ans = 1;
	unordered_map<int, int> map;
	for(int i = 0; i < arr.size(); i++){
		int tmp = arr[i] - difference;
		if(map.count(tmp)){
			// 可能之前出现过
			map[arr[i]] = max(map[arr[i]], map[tmp] + 1);
		}else{
			map[arr[i]] = 1;
		}

		ans = max(ans, map[arr[i]]);
	}

	return ans;
}
int main(){
	// vector<int>arr = {1,2,3,4};
	// vector<int>arr = {1,3,5,7};
	// int difference = 1;
	vector<int>arr = {1,5,7,8,5,3,4,2,1};
	int difference = -2;
	int ans = longestSubsequence(arr, difference);
	cout<< ans<< endl;

	return 0;
}

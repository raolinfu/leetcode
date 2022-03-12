#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
		long ans = 0;
		int mod = pow(10, 9) + 7;
		int n = arr.size();
		sort(arr.begin(), arr.end());
		unordered_map<int, long> mp;
		for(auto n: arr)
			mp.insert({n , 1});

		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				if(arr[i] % arr[j] == 0 && mp.count(arr[i] / arr[j])){
					mp[arr[i]] = (mp[arr[i]] + mp[arr[j]] * mp[arr[i] / arr[j]]) % mod;
				}
			}
		}
		for(auto iter: mp){
			ans += iter.second;
			ans %= mod;
		}

		return ans;
    }
};

int main(){
	vector<int>arr = {2, 4, 5, 10};
	Solution s;
	int ans = s.numFactoredBinaryTrees(arr);
	cout<< ans<< endl;
	return 0;
}

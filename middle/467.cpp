#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int findSubstringInWraproundString(string p) {
		int ans = 0;
		int left = 0;
		int right = 0;
		vector<int> mp(26, 0);
		while(right < p.length()){
			mp[p[right] - 'a'] = max(mp[p[right] - 'a'], 1);
			right++;
			while(right < p.length() && 
					((p[right] == 'a' && p[right - 1] == 'z') ||
					 p[right] == p[right - 1] + 1))
			{
				int idx = p[right] - 'a';
				mp[idx] = max(mp[idx], right - left + 1);
				right++;
			}
			left = right;
		}
		for(auto n: mp)
			ans += n;
		return ans;
    }
};

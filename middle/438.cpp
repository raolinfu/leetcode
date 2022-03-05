#include<vector>
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		unordered_map<char, int> mp1;
		unordered_map<char, int> mp2;
		int match = 0;
		for(auto ch: p )
			mp1[ch]++;

		int left = 0;
		int right = 0;
		while(right < s.length()){
			while(match < mp1.size() && right < s.length()){
				char ch = s[right];
				mp2[ch]++;
				if(mp1.count(ch) && mp2[ch] == mp1[ch])
					match++;
				right++;
			}
			while(match >= mp1.size() && left < right){
				if(match == mp1.size() && right - left == p.length())
						ans.push_back(left);
				char ch = s[left];
				mp2[ch]--;
				if(mp1.count(ch) && mp2[ch] < mp1[ch])
					match--;
				left++;
			}
		}

		return ans;
    }
};
int main(){
	Solution sol;
	/* string s = "cbaebabacd";
	 * string p = "abc"; */
	string s = "abab";
	string p = "ab";
	auto ans = sol.findAnagrams(s, p);
	for(auto e: ans)
		cout<< e<< "\t";
	cout<< endl;
	return 0;
}

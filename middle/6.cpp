#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
		if(numRows == 1)
			return s;
		string ans;
		vector<string> strs(numRows);
		bool up2down = false;
		for(int i = 0; i < s.length(); i++){
			int idx = i % (numRows - 1);
			if(idx == 0)
				up2down = !up2down;
			// 从上到下，第一元素
			if(idx == 0 && up2down){
				strs[idx] += s[i];
			}
			// 从上到下，最后元素
			else if(idx == 0 && !up2down){
				strs[numRows - idx] += s[i];
			}
			else if(idx > 0 && up2down){
				strs[idx] += s[i];
			}
			else if(idx > 0 && !up2down){
				strs[numRows - 1 - idx] += s[i];
			}
		}
		for(auto str: strs)
			ans += str;

		return ans;
    }
};

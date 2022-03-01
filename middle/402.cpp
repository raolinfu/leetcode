#include<string>
#include<iostream>
using namespace std;
class Solution{
	public:
		string removreKdigits(string num, int k){
			string ans;
			int i = 0;
			while(i < num.length() && k > 0){
				while(!ans.empty() && ans.back() > num[i] && k > 0){
					k--;
				}
				if(!(ans.empty() && num[i] == '0'))
					ans.push_back(num[i]);
				i++;
			}
			if(i < num.length())
				ans += num.substr(i + 1);

			return ans;
		}
};

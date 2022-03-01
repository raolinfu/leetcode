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
					ans.pop_back();
					k--;
				}
				ans.push_back(num[i]);
				if(k == 0)
					break;
				i++;
			}
			while(k > 0 && !ans.empty()){
				k--;
				ans.pop_back();
			}

			if(i < num.length())
				ans += num.substr(i + 1);

			int j = 0;
			while(j < ans.size() && ans[j] == '0'){
				j++;
			}
			string res = ans.substr(j);

			return res.empty()? "0": res.substr(j);
		}
};

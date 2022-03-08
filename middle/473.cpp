#include<vector>
#include<algorithm>
#include<unordered_set>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
		int sum = 0;
		for(auto n: matchsticks)
			sum += n;
		if(sum % 4)
			return false;
		string used(matchsticks.size(), '0');
		sort(matchsticks.begin(), matchsticks.end());
		int base = sum / 4;

		return findMatch(matchsticks, 0, used, base, base);
    }

	bool findMatch(vector<int>& matchsticks, int cnt, string& used, int res, int& base){
		if(cnt == 4)
			return true;
		if(st.count(used))
			return false;
		for(int i = 0 ; i < matchsticks.size(); i++){
			if(used[i] == '1')
				continue;
			if(matchsticks[i] > res)
				break;
			else if(matchsticks[i] == res){
				used[i] = '1';
				if(findMatch(matchsticks, cnt + 1, used, base, base))
					return true;
				used[i] = '0';
			}
			else if(matchsticks[i] < res){
				used[i] = '1';
				if(findMatch(matchsticks, cnt, used, res - matchsticks[i], base))
					return true;
				used[i] = '0';
			}
		}

		st.insert(used);

		return false;
	}
private:
	unordered_set<string> st;
};

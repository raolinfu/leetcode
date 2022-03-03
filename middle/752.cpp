#include<string>
#include<iostream>
#include<unordered_set>
#include<queue>
#include<vector>
using namespace std;
class Solution{
	public:
		int openLock(vector<string>& deadends, string target){
			int ans = 0;
			queue<string> q;
			unordered_set<string> set(deadends.begin(), deadends.end());
			if(set.count("0000"))
                return -1;
			q.push("0000");
			while(!q.empty()){
				int len = q.size();
				for(int k = 0; k < len; k++){
					string cur = q.front();
					q.pop();
					if(cur == target)
						return ans;
					for(int i = 0; i < 4; i++){
						auto tmp = spin(cur, i);
						if(!set.count(tmp.first)){
							set.insert(tmp.first);
							q.push(tmp.first);
						}
						if(!set.count(tmp.second)){
							set.insert(tmp.second);
							q.push(tmp.second);
						}
					}
				}
				ans++;
			}

			return -1;
		}

		pair<string, string> spin(string& str, int i){
			string str1 = str;
			string str2 = str;
			if(str[i] == '0'){
				str1[i] = '1';
				str2[i] = '9';
				return {str1, str2};
			}else if(str[i] == '9'){
				str1[i] = '0';
				str2[i] = '8';
				return {str1, str2};
			}else {
				str1[i] -= 1;
				str2[i] += 1;
				return {str1, str2};
			}
		}
};
int main(){
	Solution s;
	vector<string> deadends = {"0101", "0102", "0201", "1212", "2002"};
	string target = "0202";
	cout<< s.openLock(deadends, target)<< endl;
	return 0;
}

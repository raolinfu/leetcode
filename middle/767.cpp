#include<string>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
		int len = s.length();
		if(len == 1)
			return s;
		unordered_map<char, int> mp;
		priority_queue<pair<int, char>> q;
		string str;
		for(auto ch: s){
			mp[ch]++;
			if(mp[ch] > (len + 1) / 2)
				return str;
		}
		for(auto iter: mp){
			q.push({iter.second, iter.first});
		}
		while(q.size() >= 2){
			auto p1 = q.top();
			q.pop();
			auto p2 = q.top();
			q.pop();
			char ch1 = p1.second;
			char ch2 = p2.second;
			int n1 = p1.first;
			int n2 = p2.first;
			for(int i = 0; i < n2; i++){
				str += ch1;
				str += ch2;
			}
			if(n1 > n2)
				q.push({n1 - n2, ch1});
		}
		if(q.size() == 1){
			auto p = q.top();
			char ch = p.second;
			string tmp;
			int n = p.first;
			int i = 0;
			str += ch;
			n--;
			while(i < n){
				tmp += ch;
				tmp += str[i];
				i++;
			}
			while(i < str.length()){
				tmp += str[i];
				i++;
			}
			
			return tmp;
		}else{
			return str;
		}
    }
};

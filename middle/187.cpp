#include<map>
#include<string>
#include<vector>
#include<iostream>

using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
	map<string, int> m;
	vector<string> res;
	int i = 0;

	while(i + 10 <= s.length()){
		string tmp = s.substr(i, 10);
		if(m.find(tmp) != m.end() && m[tmp] == 0){
			res.push_back(tmp);
			m[tmp]++;
		}else{
			m.insert({tmp, 0});
		}
		i++;
	}
	
	return res;
}

int main(){
	string s = "AAAAAAAAAAA";
	vector<string> res = findRepeatedDnaSequences(s);

	return 0;
}

#include<string>
#include<algorithm>
#include<iostream>

using namespace std;
bool isValid = false;

bool validP(string &p);
bool process(string &s, string &p, int b1, int b2);
bool isMatch(string s, string p) {
	if(!validP(p))
		return false;
	return process(s, p, 0, 0);
}

bool process(string &s, string &p, int b1, int b2){
	int i = b1;
	int j = b2;
	while(true)
	{
		if(isalpha(p[j])){
			if(p[j] == s[i]){
				i++;
				j++;
			}else if(j + 1 < p.length() && p[j + 1] == '*'){
				j += 2;
			}
			else{
				return false;
			}
		}else if(p[j] == '.'){
				j++;
				i++;
		}else if(p[j] == '*'){
			if(p[j - 1] == '.'){
				for(int k = i + 1; k <= s.length(); k++){
					if(process(s, p, k, j + 1))
						return true;
				}
				return false;
				// 若p[j]为* 且p[j - 1]前一个可以与s[i]匹配
			}else if(p[j - 1] == s[i]){
				i++;
				if(process(s, p, i, j + 1))
					return true;
			}
				// 若p[j]为* 且p[j - 1]前一个不可以与s[i]匹配
			else{
				j++;
			}
		}
		if(i == s.length() && j == p.length())
		{
			return true;
		}
		else if(i == s.length()){
			if(p[j] == '*')
				j++;
			while(j+1 < p.length() && p[j + 1 == '*'])
				j+=2;
			if(j == p.length())
				return true;
			else
				return false;
		}else if(j == p.length()){
			return false;
		}
	}
}

bool validP(string &p){
	for(int i = 0; i < p.length(); i++){
		if(!isalpha(p[i]) && p[i] != '.' && p[i] != '*')
			return false;
		if(i > 0 && p[i] == '*' && p[i - 1] == '*')
			return false;
		if(p[0] == '*')
			return false;
	}

	return true;
}

int main(){
	string s = "aaa";
	string p = "ab*a*c*a";
	bool res = isMatch(s, p);

	cout<< res<< endl;
	return 0;

}

#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
		string ans;
		int i = 0;
		int j = s.length() - 1;
		while(s[i] == ' ')
			i++;
		while(s[j] == ' ')
			j--;
		for(int k = i; k <= j; k++){
			if(s[k] == ' '){
				if(ans.back() != ' ')
					ans.push_back(s[k]);
			}
			else{
				ans.push_back(s[k]);
			}
		}
		reverse(ans, 0, ans.length() - 1);
		cout<< ans<< endl;
		i = 0;
		j = 0;
		while(i < ans.length() && j < ans.length()){
			while(i > 0 && ans[i - 1] != ' ')
				i++;
			j = i;
			while(j + 1 < ans.length() && ans[j + 1] != ' ')
				j++;
			cout<< "i:"<< i<< " j:"<< j<< endl;

			reverse(ans, i, j);
			i = j + 1;
		}
		cout<< ans<< endl;

		return ans;
    }

	void reverse(string& str, int i, int j){
		while(i < j){
			char tmp = str[j];
			str[j] = str[i];
			str[i] = tmp;
			i++;
			j--;
		}
	}
};
int main(){
	Solution sol;
	// string str = " hello world ";
	// string str = " a hello world ";
	string str = " a hello world a ";
	sol.reverseWords(str);
	return 0;
}

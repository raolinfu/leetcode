#include<stack>
#include<iostream>
#include<string>
using namespace std;
int longestValidParentheses(string s) {
	int ans = 0;
	stack<int> st;
	st.push(-1);
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '(')
			st.push(i);
		else {
			st.pop();
			if(!st.empty()){
				ans = max(ans, i - st.top());
			}else{
				st.push(i);
			}
		}
	}

	return ans;
}
int main(){
	// string s = "(()))";
	// string s = ")()())";
	string s = "))))))";
	int ans = longestValidParentheses(s);
	cout<< ans<< endl;
	return 0;
}

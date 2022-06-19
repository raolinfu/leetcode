#include<stack>
#include <vector>
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

int longestValidParentheses1(string s) {
    int ans = 0;
    vector<int> nums(s.size() + 1);
    stack<int> st;
    int l = 0;
    nums[0] = 0;
    st.push(0);

    for (int i = 1; i <= s.size(); i++) { 
        if (s[i - 1] == '(')
            l++;
        else
            l--;
        nums[i] = l;
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }

        if (!st.empty() && nums[st.top()] == l) {
            ans = max(ans, i - st.top());
        } else {
            st.push(i);
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

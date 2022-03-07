#include<string>
#include<cmath>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string s) {
		int ans = 0, bal = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                bal++;
            } else {
                bal--;
                if (s[i-1] == '(')
                    ans += 1 << bal;
            }
        }

        return ans;
    }
/*     int recursive(string& s, int idx){
 *         if(idx == s.length())
 *             return 0;
 *         while(idx < s.length() && s[idx] == ')')
 *             idx++;
 *         bool isLeft = true;
 *         int l = 0;
 *         int r = 0;
 *         int i = idx;
 *         int ans = 0;
 *         while(i < s.length()){
 *             if(s[i] == '(' && isLeft)
 *                 l++;
 *             if(s[i] == ')'){
 *                 r++;
 *                 ans++;
 *                 isLeft = false;
 *                 if(r == isLeft){
 *                     ans += recursive(s, i);
 *                     break;
 *                 }
 *             }
 *             if(s[i] == '(' && !isLeft){
 *                 ans += recursive(s, i);
 *                 break;
 *             }
 *             i++;
 *         }
 *
 *         return pow(2, l - r) * ans;
 *     } */
};

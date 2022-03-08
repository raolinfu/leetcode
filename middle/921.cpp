#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
// need记录需要的右括号数,  res记录需要插入的括号数
        int need = 0, res = 0; 
        for(char c : s) {
            if(c == '(') {
                need++;
            }
            if(c == ')') {
                need--;
                if(need == -1) {
                    need = 0;
                    res++;
                }
            }
        }
        return res + need;
    }
};

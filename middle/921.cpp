#include<string>
#include<vector>
#include<iostream>
using namespace std;
// 从左到右 如果左括号多 则添加右括号 抵消
// 如果右括号多 直到遇到一个左括号 添加左括号 抵消
int minAddToMakeValid(string s) {
    int res = 0;
    int left = 0;
    int right = 0;
    // for(int i = 0; i < s.length(); i++){
    //     if(left > 0 && right == 0){
    //         if(s[i] == '(' && s[i - 1] == '('){
    //             left++;
    //         }else if(s[i] == '(' && s[i - 1] == ')'){
    //             res += left;
    //             left = 1;
    //         }
    //         else{
    //             left--;
    //         }
    //     }else if(left == 0 && right > 0){
    //         if(s[i] == '('){
    //             res += right;
    //             left++;
    //             right = 0;
    //         }else{
    //             right++;
    //         }
    //     }else if(left == 0 && right == 0){
    //         if(s[i] == '('){
    //             left++;
    //         }else{
    //             right++;
    //         }
    //     }
    // }
    // res += right;
    return res;
}
int main(int argc, char const *argv[])
{
    // string str = "())";
    string str = ")))";
    int res = minAddToMakeValid(str); 
    cout<< res<< endl;
    return 0;
}

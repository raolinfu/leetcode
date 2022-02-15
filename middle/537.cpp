#include<string>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
		int a = stoi(num1);
        int c = stoi(num2);
        // 找到+位置，并得到 b 和 d
        int i = 0;
        while (num1[i] != '+')
        {
            ++i;
        }
        int b = stoi(num1.substr(i+1));
        i = 0;
        while (num2[i] != '+')
        {
            ++i;
        }
        int d = stoi(num2.substr(i+1));
        return to_string(a*c - b*d) + "+" + to_string(a*d+b*c) + "i";
    }
};


#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		string res;
		int l1 = num1.length();
		int l2 = num2.length();
		vector<int> dp(l1 + l2, 0);
		for (int i = 0; i < l1; i++) {
			for (int j = 0; j < l2; j++) {
				int x = num1[i] - '0';
				int y = num2[j] - '0';
				dp[i + j + 1] += x * y;
			}
		}

		for (int i = l1 + l2 - 1; i > 0; --i) {
			dp[i - 1] += dp[i] / 10;
			dp[i] %= 10;
		}
		int begin = dp[0] == 0? 1: 0;
		for (int i = begin; i < l1 + l2; i++) {
			res += '0' + dp[i];
		}

		return res;
    }
};

int main(){
	string num1;
	string num2;
	cin>> num1>> num2;
	cout<< num1<< endl;
	cout<< num2<< endl;
	Solution sol;
	cout<< sol.multiply(num1, num2)<< endl;
	return 0;
}

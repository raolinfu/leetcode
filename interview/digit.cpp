#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
	public:
		void getDigit(int high, int low, int d) {
			int res = helper(high, d) - helper(low - 1, d);
		}

		int helper(int n, int d) {
			string str = to_string(n);
			int len = str.length();
			int res = 0;
			if (d != 0) {
				for (int i = 1; i <= len; i++) {
					int a = n / (int)pow(10, i);
					res += a * pow(10, i - 1);
					int y = str[len - i] - '0';
					if (y > d)
						res += pow(10, i - 1);
					else if (y == d)
						res += n % (int)pow(10, i - 1) + 1;
				}
			} else if (d == 0) {
				for (int i = 1; i < len; i++) {
					int a = n / (int)pow(10, i);
					res += (a - 1) * pow(10, i - 1);
					int y = str[len - i] - '0';
					if (y > d)
						res += pow(10, i - 1);
					else if (y == d)
						res += n % (int)pow(10, i - 1) + 1;
				}
			}

			cout<< res<< endl;
			return res;

		}
};

int main(){
	int high;
	int low;
	int d;
	cin>> high>> low>> d;
	Solution sol;
	sol.getDigit(high, low, d);

	return 0;
}

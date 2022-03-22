#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int secondStart = 1; secondStart < n - 1; ++secondStart) {
            if (num[0] == '0' && secondStart != 1) {
                break;
            }
            for (int secondEnd = secondStart; secondEnd < n - 1; ++secondEnd) {
                if (num[secondStart] == '0' && secondStart != secondEnd) {
                    break;
                }
                if (valid(secondStart, secondEnd, num)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool valid(int secondStart, int secondEnd, string num) {
        int n = num.size();
        int firstStart = 0, firstEnd = secondStart - 1;
        while (secondEnd <= n - 1) {
            string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
            int thirdStart = secondEnd + 1;
            int thirdEnd = secondEnd + third.size();
            if (thirdEnd >= n || !(num.substr(thirdStart, thirdEnd - thirdStart + 1) == third)) {
                break;
            }
            if (thirdEnd == n - 1) {
                return true;
            }
            firstStart = secondStart;
            firstEnd = secondEnd;
            secondStart = thirdStart;
            secondEnd = thirdEnd;
        }
        return false;
    }

    string stringAdd(string s, int firstStart, int firstEnd, int secondStart, int secondEnd) {
        string third;
        int carry = 0, cur = 0;
        while (firstEnd >= firstStart || secondEnd >= secondStart || carry != 0) {
            cur = carry;
            if (firstEnd >= firstStart) {
                cur += s[firstEnd] - '0';
                --firstEnd;
            }
            if (secondEnd >= secondStart) {
                cur += s[secondEnd] - '0';
                --secondEnd;
            }
            carry = cur / 10;
            cur %= 10;
            third.push_back(cur + '0');
        }
        reverse(third.begin(), third.end());
        return third;
    }
};
string strAdd(string& str1, string& str2) {
	string ans;
	int carry = 0;
	int i = str1.length() - 1;
	int j = str2.length() - 1;
	while (i >= 0 || j >= 0 || carry != 0) {
		int cur = carry;
		if (i >= 0)
			cur += str1[i--] - '0';
		if (j >= 0)
			cur += str2[j--] - '0';
		carry = cur / 10;
		cur = cur % 10;
		ans.push_back('0' + cur);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
int main() {
	string str1 = "12875";
	string str2 = "87452";
	cout<< strAdd(str1, str2)<< endl;
	
	return 0;
}


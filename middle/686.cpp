#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
		int len1 = a.length();
		int len2 = b.length();
		int ans = 0;
		string tmp;
		while (tmp.length() < len2) {
			tmp += a;
		}
		while (true) {
			while (tmp.find(b) != string::npos) {
				return ans;
			}
			if (tmp.length() > len2 * 2 && tmp.length() > len1 * 2) {
				return -1;
			}
			ans++;
			tmp += a;
		}
    }
};

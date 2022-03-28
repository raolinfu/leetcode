#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
		return fun(n);
    }
    long fun(long n) {
		if (mp.count(n))
			return mp[n];
		if (n == 1)
			return 0;
		if (n == 2)
			return 1;
		int ans;
		if (n % 2 == 0) {
			ans = fun(n / 2) + 1;
		} else {
			long cnt1;
			long cnt2;
			long n1 = n - 1;
			long n2 = n + 1;
			cnt1 = fun(n1);
			cnt2 = fun(n2);
			ans = min(cnt1, cnt2) + 1;
		}
		mp.insert({n, ans});

		return ans;
    }

private:
	unordered_map<long, long> mp;
};

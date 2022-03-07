#include<string>
#include<cmath>
#include<deque>
using namespace std;
class Solution {
public:
    int primePalindrome(int n) {
		int low = pow(10, 7);
		int high = pow(10, 8);
		while (true) {
            if (n == reverse(n) && isPrime(n))
				break;
            n++;
			// 不存在长度为8的素数
            if (low < n && n < high)
                n = high;
        }

		return n;
    }
	// 直接判断一个数是不是回文数和素数
	bool isPrime(int N) {
        if (N < 2) return false;
        int R = (int)sqrt(N);
        for (int d = 2; d <= R; ++d)
            if (N % d == 0) return false;
        return true;
    }

    int reverse(int N) {
        int ans = 0;
        while (N > 0) {
            ans = 10 * ans + (N % 10);
            N /= 10;
        }
        return ans;
    }

	bool dfs(int& ans, int& low, int& high, int num, string str){
		if(str.front() != '0'){
			for(int i = 1; i <= 9; i++){
				int n = i * pow(10, str.length() + 1) + i + num * 10;
				if(n > low && n < high){
					ans = n;
					return true;
				}
				else if(ans > high){
					return false;
				}
				else if(ans < low){
					string tmp;
					tmp += (i + 'a');
					tmp += str;
					tmp += (i + 'a');
					if(dfs(ans, low, high, n, tmp))
						return true;
				}
			}
		}

		return false;
	};
};

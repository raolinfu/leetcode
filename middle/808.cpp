#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    double soupServings(int n) {
		n = n/25 + (n%25 > 0 ? 1 : 0);
        if (n >= 500) return 1.0;

        vector<vector<double>> memo(n+1, vector<double>(n + 1));
        for (int s = 0; s <= 2*n; ++s) {
            for (int i = 0; i <= n; ++i) {
                int j = s-i;
                if (j < 0 || j > n) continue;
                double ans = 0.0;
                if (i == 0) ans = 1.0;
                if (i == 0 && j == 0) ans = 0.5;
                if (i > 0 && j > 0) {
                    ans = 0.25 * (memo[M(i-4)][j] + memo[M(i-3)][M(j-1)] +
                                  memo[M(i-2)][M(j-2)] + memo[M(i-1)][M(j-3)]);
                }
                memo[i][j] = ans;

            }
        }
        return memo[n][n];

		// return helper(n, n, 1);
    }
	int M(int x) { return max(0, x); }

	// 超时
	double helper(int a, int b, double p){
		string str = std::to_string(a) + '!' + std::to_string(b);
		if(mp1.count(str)){
			return mp1[str];
		}
		if(a == 0 && b > 0){
			mp1.insert({str, p});
			return p;
		}
		if(a == 0 && b == 0){
			mp1.insert({str, 0.5 * p});
			return 0.5 * p;
		}
		if(a > 0 && b == 0){
			mp1.insert({str, 0});
			return 0;
		}
		double p1 = helper(max(a - 100, 0), b, 0.25 * p);
		double p2 = helper(max(a - 75, 0), max(b - 25, 0), 0.25 * p);
		double p3 = helper(max(a - 50, 0), max(b - 50, 0), 0.25 * p);
		double p4 = helper(max(a - 25, 0), max(b - 75, 0), 0.25 * p);
		double s = p1 + p2 + p3 + p4;
		mp1.insert({str, s});
		return s;
	}
private:
	unordered_map<string, double> mp1;
};

#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
// f(i) = min(f(j)) + 1  
int numSquares(int n) {
	vector<int> f(n + 1);
	for(int i = 1; i <= n; i++){
		int mi = INT_MAX;
		for(int d = 1; d * d <= i; d++){
			mi = min(f[i - d * d] + 1, mi);
		}	
		f[i] = mi;
	}

	return f[n];
}
	

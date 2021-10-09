#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
/*
 *寻找小于n的素数个数
 * */
int countPrimes(int n) {
	long res = 0;
	if(n < 2)
		return 0;
	vector<bool> prime(n, 1);
	for(long i = 2; i < n; i++){
		if(prime[i]){
			res++;
			for(long j = i; j * i < n; j++){
				prime[j * i] = 0;
			}
		}
	}

	return res;
}


int main(){
	int n = 10;
	int res = countPrimes(n);
	return 0;
}


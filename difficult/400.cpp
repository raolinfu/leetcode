#include<iostream>
#include<cmath>
using namespace std;

int findNthDigit(int n) {
	int res;
	int b = 1;
	int cur = 0;

	while(n > cur +	b * 9 * (int)pow(10, b - 1)){
		cur += b * 9 * pow(10, b - 1);
		b++;
	};
	cout << "b: "<< b<< " cur: "<< cur<< endl;
	int c = (n - cur) / b + (int)pow(10, b - 1) - 1;
	cout << c<< endl;
	int m = (n - cur) % b;
	if(m == 0)
		return 9;
	res = c % (int)pow(10, b - m + 1) / (int)pow(10, b - m);

	return res;
}

int main(){
	// int n = 11;
	// int n = 9;
	int n = 132100;
	int res = findNthDigit(n);
	cout << res<< endl;
	return 0;
}

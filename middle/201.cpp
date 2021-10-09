#include<iostream>
int rangeBitwiseAnd(int left, int right) {
	int n = 1 << 30;
	int res = 0;
	while((left & n) == (right & n) && n){
		res |= (left & n);
		n >>= 1;
	}
	return res;
}

int main(){
	int left = 5;
	int right = 7;
	int res = rangeBitwiseAnd(left, right);
	return 0;
}

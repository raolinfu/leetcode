#include<iostream>

int trailingZeroes(int n) {
	int res = 0;
	int base = 5;
	while(n / base){
		res += n /base;
		base *= 5;
	}

	return res;

}


int main(){
	int n = 10;
	int res = trailingZeroes(n);
	std::cout<< res<< std::endl;
	return 0;
}

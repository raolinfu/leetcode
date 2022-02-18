#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
		int n = sqrt(c);
		for(int i = 0; i <= n; i++){
			int res = c - i * i;
			int t = sqrt(res);
			if(t < i)
				return false;
			if(t * t == res){
				cout<< i<< "\t"<< t<< endl;
				return true;
			}
		}

		return false;
    }
};
int main(){
	Solution s;
	int c = 2;
	cout<< s.judgeSquareSum(c)<< endl;

	return 0;
}

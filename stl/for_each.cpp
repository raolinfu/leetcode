#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	vector<int> nums(10);
	int a = 0;
	generate(nums.begin(), nums.end(), [&a](){
				return a++;	
			});
	for_each(nums.begin(), nums.end(), [](const int &n){
				cout<< n<< "  ";
			});
	cout<< endl;
	return 0;
}

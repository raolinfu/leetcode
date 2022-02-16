#include<string>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
		string str;
		bool flag = false;
		while(n){
			str += ('0' + n % 10);
			n /= 10;
		}
		cout<< str<< endl;
		int i = 1;
		while(i < str.length()){
			if(str[i] < str[i - 1]){
				flag = true;
				break;
			}
			i++;
		}

		if(flag){
			int j = i - 1; 
			while(j >= 0){
				if(str[j] <= str[i])
					break;
				j--;
			}
			std::swap(str[i], str[j + 1]);
			std::reverse(str.begin(), str.end());
			std::sort(str.end() - i, str.end());
			long ans = stol(str);
			return ans > INT_MAX? -1: ans;
		}

		return -1;
    }
};
int main(){
	// int n = 12;
	// int n = 23126;
	// int n = 2312641;
	int n = 2147483486;
	Solution s;
	int ans = s.nextGreaterElement(n);
	cout<< ans<< endl;
	string str = "2314621";
	std::sort(str.end() - 3, str.end());
	cout<< str<< endl;

	return 0;
}

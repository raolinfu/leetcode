#include<string>
using namespace std;
class Solution {
public:
    int rotatedDigits(int n) {
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(isValid(i))
				ans++;
		}

		return ans;
    }
	
	bool isValid(int& n){
		string str = std::to_string(n);
		bool j = false;
		for(auto ch: str){
			if(ch == '3' || ch == '4' || ch == '7')
				return false;
			if(ch == '2' || ch == '5' || ch == '6' || ch == '9')
				j = true;
		}
		return j;
	}
};

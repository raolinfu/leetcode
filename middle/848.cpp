#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
		int n = s.length();
		long steps = 0;
		for(int i = n - 1; i >= 0; i--){
			steps += shifts[i];
			s[i] = 'a' + (s[i] - 'a' + steps) % 26;
		}

		return s;
    }
};
int main(){

	string s = "ruu";
	vector<int> shifts = {26,9,17};
	/* string s = "abc";
	 * vector<int>shifts = {3,5,9}; */
	Solution sol;
	cout<< sol.shiftingLetters(s, shifts)<< endl;

	return 0;
}

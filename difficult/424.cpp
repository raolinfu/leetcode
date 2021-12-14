#include<string>
#include<climits>
#include<iostream>
using namespace std;
int characterReplacement(string s, int k) {
int res = INT_MIN;
	int cnt;
	for(int i = 0; i < s.length(); i++){
		if(int(s.length() - i) < res)
			return res;
		if(i !=0 && s[i] == s[i - 1])
			continue;
		cnt = k;
		int j = i + 1;
		int flag = false;
		while(j < s.length()){
			if(cnt > 0 && s[j] != s[i]){
				cnt--;
			}else if(cnt == 0 && s[j] != s[i]){
				res = max(res, j - i);
				flag = true;
				break;
			}
			j++;
		}
		if(!flag){
			return max(res, j - i);
		}
	}

	return res;
}

int main(){
	/* string s = "AABABBA";
	 * int k = 1; */
	string s = "ABAB";
	int k = 2;
	int res = characterReplacement(s, k);
	cout<< res<< endl;
	return 0;
}

#include<iostream>
#include<vector>
#include<string>
using namespace std;
/* 
 *时间复杂度和空间读为
 * */
string getHint(string secret, string guess) {
	string res;
	vector<int>set(10, 0);
	int right = 0;
	int wrong = 0;
	for(int i = 0; i < secret.size(); i++){
		if(secret[i] == guess[i]){
			right++;
			continue;
		}	
		set[secret[i] - '0']++;
	}
	for(int i = 0; i < secret.size(); i++){
		if(secret[i] != guess[i] && set[guess[i] - '0']){
			wrong++;
			set[guess[i] - '0']--;
		}

	}
	res = to_string(right) + 'A' + to_string(wrong) + 'B';

	return res;
}

int main(){
	string secret = "1807";
	string guess = "7810";
	string res = getHint(secret, guess);
	cout<< res<< endl;
	return 0;
}

#include<iostream>
#include<string>
#include<map>

using namespace std;

string getRes(int numerator, int denominator){
	int i = 0;
	string res;

	while(numerator < denominator){
		numerator *= 10;
		res = res == ""? "0.": res + "0";
		i++;
	}

	int pre = numerator / denominator;
	int n = numerator % denominator;
	map<int, int> m;
	res += to_string(pre);
	m.insert({pre, i});

	while(n){
		n *= 10;
		pre = n / denominator;
		n = n % denominator;
		if(m.find(pre) == m.end())
		{
			m.insert({pre, i});
			res += to_string(pre);
		}
		else{
			res.insert(m[pre], "(");
			res.push_back(')');
			return res;
		}
		i++;
	}

	return res;
}


int main(){
	string res;
	res = getRes(1, 13);
	return 0;
}

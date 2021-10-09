#include<string>
#include<iostream>

using namespace std;

int cmpVersion(string &ver1, string &ver2){
	int l1 = ver1.length();
	int l2 = ver2.length();
	int n1 = 0;
	int n2 = 0;
	while(n1 < l1 || n2 < l2){
		string str1;
		string str2;
		
		while(n1 < l1 && ver1[n1] == '0'){
			n1++;
			continue;
		}
		while(n1 < l1 && ver1[n1] != '.'){
			str1 += ver1[n1];
			n1++;
		}
		n1++;

		while(n2 < l2 && ver2[n2] == '0'){
			n2++;
			continue;
		}
		while(n2 < l2 && ver2[n2] != '.'){
			str2 += ver2[n2];
			n2++;
		}
		n2++;

		str1 = str1 == ""? "0": str1;
		str2 = str2 == ""? "0": str2;
		if(stoi(str1) > stoi(str2))
			return 1;
		else if(stoi(str1) < stoi(str2))
			return -1;
	}
	
	return 0;
}



int main(){
	string str1 = "0.1.3";
	string str2 = "0.2";

	cout<< cmpVersion(str1, str2)<< endl;
	return 0;
}

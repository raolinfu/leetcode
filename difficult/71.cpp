#include<string>
#include<vector>
#include<iostream>
using namespace std;

string simplifyPath(string path) {
	string res ;
	string tmp;
	vector<string> strs;
	for(int i = 0; i < path.length(); i++){
		if(path[i] != '/'){
			tmp.push_back(path[i]);
		}else{
			if(tmp == ".." && !strs.empty()){
				strs.pop_back();
			}
			else if(!tmp.empty() && tmp != ".."){
				strs.push_back(tmp);
			}
			tmp.clear();
		}
	}
	for(int i = 0; i < strs.size(); i++){
		res += "/" + strs[i];
	}
	return res; 
}

int main(){
	// string path = "/home//foo/";
	string path = "/a/./b/../../c/";
	// string path = "/../";
	string res = simplifyPath(path);
	cout<< res<< endl;
	return 0;
}

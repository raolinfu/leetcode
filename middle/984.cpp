#include<string>
#include<list>
#include<iostream>
using namespace std;
class Solution {
public:
    string strWithout3a3b(int a, int b) {
		list<int> li;
		string ans;
		int n = min(a, b);
		int m = max(a, b);
		int diff = m - n;
		char ch1 = a - b >= 0? 'a': 'b';
		char ch2 = a - b >= 0? 'b': 'a';
		for(int i = 0; i < n; i++){
			li.push_back(0);
			li.push_back(1);
		}
		if(diff){
			li.push_back(0);
			diff--;
		}
		auto iter = li.begin();
		while(diff && iter != li.end()){
			if(*iter == 1)
			{
				
				li.insert(iter, 0);
				diff--;
			}
			iter++;
		}
		if(diff){
			li.push_back(0);
			diff--;
		}
		for(auto it: li){
			ans += it == 0? ch1: ch2;
		}

		return ans;
    }
};
int main(){
	int a = 4;
	int b = 1;
	Solution sol;
	cout<< sol.strWithout3a3b(a, b)<< endl;
	return 0;
}

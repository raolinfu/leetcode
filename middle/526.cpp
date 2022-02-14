#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
private:
	unordered_set<int> set;

public:
    int countArrangement(int n) {
		int ans = 0;
		int cnt = 1;
		process(n, ans, cnt);

		return ans;
    }

	void process(int& n, int& ans, int cnt){
		if(cnt == n + 1)
		{
			ans++;
			return;
		}
		for(int i = 1; i <= n; i++){
			if(set.count(i) == 0)
			{
				if(i % cnt == 0 || cnt % i == 0){
					set.insert(i);
					process(n, ans, cnt + 1);
					set.erase(i);
				}
			}
		}
	}
};
int main(){
	Solution solution;
	// int n = 2;
	int n = 7;
	int ans = solution.countArrangement(n);
	cout<< ans<< endl;
	return 0;
}

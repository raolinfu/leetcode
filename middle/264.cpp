#include<vector>
#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

void process(int &n, vector<int> &nums, int base);
int nthUglyNumber(int n) {
	vector<int> nums;
	nums.push_back(1);
	process(n, nums, 0);
	return *nums.rbegin();
}

void process(int &n, vector<int> &nums, int base){
	if(n == nums.size())
		return;
	int end = *nums.rbegin();
	int c1 = end * 2;
	int c2 = end * 3;
	int c3 = end * 5;
	
	if(c1 < base)
		nums.push_back(c1);
	else
		return;

	end = *nums.rbegin();
	if(c2 < end){
		process(n, nums, base);
	}
	else if(c2 < base)
		nums.push_back(c2);

	end = *nums.rbegin();
	if(c3 < end){
		process(n, nums, base);
	}
	else if(c2 < base)
		nums.push_back(c3);
}

int nthUglyNumber1(int n) {
	priority_queue<long, vector<long>, greater<long>> heap;	
	heap.push(1);
	vector<int> factor = {2, 3, 5};
	unordered_set<long> set;
	long cur = 0; 
	for(int i = 0; i < n; i++){
		cur = heap.top();
		for(int f: factor){
			if(set.find(f * cur) != set.end()){
				heap.push(f * cur);
				set.insert(f * cur);
			}
		}
		heap.pop();
	}
	
	return cur;

}

int main(){
	int n = 10;
	int res = nthUglyNumber(n);
	cout << res<< endl;
	return 0;
}


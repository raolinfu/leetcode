#include<vector>
#include<queue>
#include<iostream>
using namespace std;

struct Sum{
	int idx1;
	int idx2;
	int data;
	bool operator>(const Sum &a) const{
		return this->data > a.data;
	};
};
// 算法复杂读为O(mn)超时
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	vector<vector<int>> res;
	priority_queue<Sum, vector<Sum>, greater<Sum>> q;
	for(int i = 0; i < nums1.size(); i++){
		for(int j = 0; j < nums2.size(); j++){
			q.push({i, j, nums1[i] + nums2[j]});
		}
	}
	for(int i = 0; i < k; i++){
		if(!q.empty()){
			Sum t = q.top();
			res.push_back(vector<int>{nums1[t.idx1], nums2[t.idx2]});
			q.pop();
		}else
			break;
	}

	return res;
}

// O(k)的复杂度
vector<vector<int>> kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
	vector<vector<int>> res;
	priority_queue<Sum, vector<Sum>, greater<Sum>> q;
	for(int i = 0; i < min(k, (int)nums1.size()); i++){
		q.push({i, 0, nums1[i] + nums2[0]});
	}
	while(!q.empty() && res.size() < k){
		Sum t = q.top();
		res.push_back(vector<int>{nums1[t.idx1], nums2[t.idx2]});
		q.pop();
		// 注意这里下标加1
		if(t.idx2 + 1< nums2.size()){
			q.push({t.idx1, t.idx2 + 1, nums1[t.idx1] + nums2[t.idx2 + 1]});
		}
	}

	return res;
}
int main(){
	vector<int>	nums1 = {1,7,11};
	vector<int> nums2 = {2,4,6};
	int k = 3;
	vector<vector<int>> res = kSmallestPairs1(nums1, nums2, k);
	for(auto v: res){
		for(auto ele: v){
			cout<< ele<<"\t";
		}
		cout<< endl;
	}
	return 0;
}

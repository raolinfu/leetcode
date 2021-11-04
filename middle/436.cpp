#include<vector>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
struct Ele{
	pair<int, int> interval;
	int idx;
	bool operator<(const Ele& ele){
		if(this->interval.first < ele.interval.first)
			return true;
		else if(this->interval.first == ele.interval.first)
			return this->interval.second < ele.interval.second;
		return false;
	}
};
struct Comp{
	bool operator()(const Ele& a, const Ele& b){
		return a.interval.first < b.interval.second;
	}
};
bool cmp(const Ele &a, const Ele& b)
{
    return a.interval.first < b.interval.second;
}
vector<int> findRightInterval(vector<vector<int>>& intervals) {
	vector<int> res(intervals.size(), -1);
	vector<Ele> eles;
	for(int i = 0; i < intervals.size(); i++){
		eles.push_back({make_pair(intervals[i][0], intervals[i][1]), i});
	}
	sort(eles.begin(), eles.end());

	for(int i = 0; i < eles.size(); i++){
		// 这里i后不需要+1 因为自身first可能和second相等
		auto d = lower_bound(eles.begin() + i, eles.end(), eles[i], Comp());
		if(d != eles.end())
			res[eles[i].idx] = d->idx;
	}
	return res;
}

int main(){
	// vector<vector<int>> intervals = {{3,4},{2,3},{1,2}};
	vector<vector<int>> intervals = {{1,4},{2,3},{3,4}};
	// vector<vector<int>>	intervals = {{1,2}};
	vector<int> res = findRightInterval(intervals);
}

#include<vector>
#include<queue>
#include<unordered_set>
#include<iostream>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
	unordered_set<int> set;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int idx = q.front();
		// 只有某个房间的钥匙串没有放过时 才放入
		if(!set.count(idx)){
			for(auto ele: rooms[idx]){
				if(!set.count(ele)){
					q.push(ele);
				}
			}
			set.insert(idx);
		}
		q.pop();
	}

	return set.size() == rooms.size();
}

int main(){
	// vector<vector<int>> rooms = {{1},{2},{3},{}};
	vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
	int res = canVisitAllRooms(rooms);
	cout<< res<< endl;
	return 0;
}

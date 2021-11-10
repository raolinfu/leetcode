#include<vector>
#include<iostream>
#include<utility>
#include<queue>
using namespace std;
struct Comp{
	bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
		return a.first > b.first;
	}
};
int kthSmallest(vector<vector<int>>& matrix, int k) {
	int cnt = 0;
	int rows = matrix.size();
	int cols = matrix[0].size();
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Comp> q;
	for(int i = 0; i < rows; i++)
		q.push({matrix[i][0], {i, 0}});
	while(cnt < k){
		pair<int, pair<int, int>> t = q.top();
		q.pop();
		if(t.second.second + 1 < cols)
			q.push({matrix[t.second.first][t.second.second + 1], {t.second.first, t.second.second + 1}});
		cnt++;
	}

	return q.top().first;
}

int main(){
	vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
	int k = 8;
	int res = kthSmallest(matrix, k);

	return 0;
}

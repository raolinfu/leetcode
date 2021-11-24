#include<vector>
#include<iostream>
using namespace std;

int maxDistToClosest(vector<int>& seats) {
	int res = 0;
	int preIdx = -1;
	for(int i = 0; i < seats.size(); i++){
		if(seats[i]){
			if(preIdx == -1)
				res = max(res, i);
			else
				res = max(res, (i - preIdx) / 2);
			preIdx = i;
		}
	}
	res = max(res, ((int)seats.size() - preIdx - 1));

	return res;
}

int main(){
	// vector<int> seats = {1,0,0,0,1,0,1};
	vector<int>seats = {1,0,0,0};
	int res = maxDistToClosest(seats);
	cout<< res<< endl;
	return 0;
}

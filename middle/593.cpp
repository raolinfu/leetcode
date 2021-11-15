#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
	vector<vector<int>> p; 
	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	sort(p.begin(), p.end());
	// 排除四个数都相同的情况
	if(p[0] == p[3])
		return false;
	int n1 = pow(p[0][0] - p[1][0], 2) + pow(p[0][1] - p[1][1], 2);
	int n2 = pow(p[0][0] - p[2][0], 2) + pow(p[0][1] - p[2][1], 2);
	int n3 = pow(p[3][0] - p[1][0], 2) + pow(p[3][1] - p[1][1], 2);
	int n4 = pow(p[3][0] - p[2][0], 2) + pow(p[3][1] - p[2][1], 2);
	// 排除菱形的情况
	int n5 = pow(p[3][0] - p[0][0], 2) + pow(p[3][1] - p[0][1], 2);
	return n1 == n2 && n3 == n4 && n1 == n3 && (n5 == n1 + n2);
}

int main(){
	/* vector<int>p1 = {0,0};
	 * vector<int>p2 = {1,1};
	 * vector<int>p3 = {1,0};
	 * vector<int>p4 = {0,1};
	 * vector<int>p5 = {0,1}; */
	vector<int>p1 = {1,0};
	vector<int>p2 = {-1,0};
	vector<int>p3 = {0,1};
	vector<int>p4 = {0,-1};
	vector<int>p5 = {0,1};
	vector<vector<int>> p; 
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.push_back(p1);
	sort(p.begin(), p.end());
	int n1 = 1;
	int n2 = 1;
	int n3 = 0;
	int n4 = 1;
	bool res = n1== n2 == n3 == n4;
	cout<< res<< endl;
	res = validSquare(p1, p2, p3, p4);
	cout<< res<< endl;
	cout<< pow(-1, 2)<< endl;
	return 0;
}

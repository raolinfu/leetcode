#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
int hIndex(vector<int>& citations) {
	int res = 0;
	int len = citations.size();
	sort(citations.begin(), citations.end());
	for(int i = 0; i < len; i++){
		if(citations[i] >= len - i)
			res = max(res, len -i);
	}
	return res;
}

int main(){
	vector<int>	citations = {3,0,6,1,5};
	int res = hIndex(citations);

	cout<< res<< endl;
}

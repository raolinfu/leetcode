#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;
 /*
  *nums[i] <= len - i
  * */
int hIndex(vector<int>& citations) {
	int len = citations.size();
	int b = 0;
	int e = len - 1;
	int res = 0;
	while(b <= e){
		int m = (b + e) >> 1;
		if(citations[m] >= len - m)
		{
			res = max(res, len - m);
			e = m - 1;
		}
		else{
			b = m + 1;	
		}
	}
	return res;
}


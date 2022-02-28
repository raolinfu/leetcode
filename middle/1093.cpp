#include<vector>
#include<climits>
#include<iostream>
using namespace std;

vector<double> sampleStats(vector<int>& count) {
	double sum = 0;
	vector<double> ans(5);
	ans[0] = INT_MAX;
	ans[1] = INT_MIN;
	int mode = 0;
	int cnt = 0;
	for(int i = 0; i < count.size(); i++){
		if(count[i] > 0){
			cnt += count[i];
			sum += double(i) * (double)count[i];
			mode = count[i] > count[mode]? i: mode;
			ans[0] = min(ans[0], (double)i);
			ans[1] = max(ans[1], (double)i);
		}
	}
	ans[2] = sum / cnt;
	ans[4] = mode;
    bool isEven = cnt % 2;
	int middle = cnt / 2;;
	int first = INT_MIN;
	int second = INT_MIN;

	cnt = 0;
	for(int i = 0; i < count.size(); i++){
		if(count[i] > 0){
			cnt += count[i];
			if(isEven && cnt > middle){
				ans[3] = i;
				first = i;
				second = i;
				break;
			}else if(!isEven && cnt == middle){
				first = i;
			}else if(!isEven && cnt > middle){
				if(first != INT_MIN){
					second = i;
					break;
				}
				first = i;
				second = i;
				break;
			}
		}
	}
	ans[3] = (double)(first + second) / 2;

	return ans;
}

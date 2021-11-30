#include<vector>
#include<climits>
#include<iostream>
using namespace std;

int maxTurbulenceSize(vector<int>& arr) {
	int ans = 1;
	int len = arr.size();
	vector<int> l(len, 1);
	vector<int> h(len, 1);
	for(int i = 1; i < len; i++){
		if(arr[i] > arr[i - 1]){
			h[i] = l[i - 1] + 1;
		}else if(arr[i] < arr[i - 1]){
			l[i] = h[i - 1] + 1;
		}

		ans = max(ans, max(h[i], l[i]));
	}

	return ans;
}
int main(){
	vector<int> arr = {9,4,2,10,7,8,8,1,9};
	int ans = maxTurbulenceSize(arr);
	cout<< ans<< endl;
	return 0;
}

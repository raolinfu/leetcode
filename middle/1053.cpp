#include<vector>
#include<iostream>
using namespace std;

vector<int> prevPermOpt1(vector<int>& arr) {
	int len = arr.size();
	int idx;
	for(int i = len - 1; i >=0; i--){
		if(i != len -1 && arr[i] > arr[i + 1]){
			for(int j = i + 1; j < len; j++){
				if(arr[j] < arr[i] && arr[j] != arr[j - 1]){
					idx = j;
				}
			}
			cout<< "idx:"<< idx<< " i:"<< i<< endl;
			int tmp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = tmp;
			break;
		}
	}

	return arr;
}
int main(){
	// vector<int> arr = {1,9,4,6,7};
	vector<int> arr = {3,1,1,3};
	for(auto n :arr)
		cout<< n<< " ";
	cout<< endl;
	vector<int> res = prevPermOpt1(arr);
	for(auto n :res)
		cout<< n<< " ";
	cout<< endl;
	return 0;
}

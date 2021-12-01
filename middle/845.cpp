// 解题思路 判断各种不同条件即可
// 方法二 动态规划 某点左侧和右侧比它小的个数
#include<vector>
#include<iostream>
using namespace std;
int longestMountain(vector<int>& arr) {
	if(arr.size() == 0)
		return 0;
	int res = 0;
	bool accend = true;
	int pre = arr[0];
	int accend_cnt = 1;
	int decend_cnt = 0;
	int i = 1;
	while(i < arr.size()){
		// 升序 且当前值小于pre
		if(accend && arr[i] < pre ){
			if(accend_cnt > 1){
				accend = false;
				decend_cnt++;
			}
		}else if(accend && arr[i] == pre){
		// 升序 且当前值等于pre
			accend_cnt = 1;
		}
		else if(accend && arr[i] > pre){
		// 升序 且当前值大于pre
			accend_cnt++;
		}else if(!accend && arr[i] < pre){
		// 降序 且当前值小于pre
			decend_cnt++;
		}else if(!accend && arr[i] == pre){
		// 降序 且当前值等于pre
			res = max(res, decend_cnt + accend_cnt);
			decend_cnt = 0;
			accend_cnt = 1;
			accend = true;
		}else if(!accend && arr[i] > pre){
		// 降序 且当前值大于pre
			res = max(res, decend_cnt + accend_cnt);
			decend_cnt = 0;
			accend_cnt = 2;
			accend = true;
		}
		pre = arr[i];
		i++;
	}
	// 最后检验 如果是降序 且降序数大于0
	if(!accend){
		res = max(res, decend_cnt + accend_cnt);
	}

	return res;
}

int main(){
	// vector<int> arr = {2,1,4,7,3,2,5};
	// vector<int> arr = {0,2,2};
	vector<int> arr = {0,2,0,2,1,2,3,4,4,1};
	int res = longestMountain(arr);
	cout<< res<< endl;
	return 0;
}

#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		vector<int> ans;
		int idx = findMostLeft(arr, x);
		if(idx == INT_MAX)
			return vector<int>(arr.end() - k, arr.end());
		else if(idx == INT_MIN)
			return vector<int>(arr.begin(), arr.begin() + k);
		int l = idx;
		int r = idx;
		int cnt = r - l + 1;
		if(cnt == k)
			return vector<int>(arr.begin() + idx, arr.begin() + idx + 1);
		while(l > 0 && r < arr.size() - 1){
			if(arr[r + 1] - x < x - arr[l - 1] )
				r++;
			else
				l--;
			cnt++;
			if(cnt == k)
				return vector<int>(arr.begin() + l, arr.begin() + r + 1);
		}
		if(l == 0 && cnt < k){
			while(cnt< k){
				cnt++;
				r++;
			}
		}else if(r == arr.size() - 1 && cnt < k){
			while(cnt< k){
				cnt++;
				l--;
			}
		}

		return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }

	int findMostLeft(vector<int>& arr, int tar){
		int l = 0;
		int r = arr.size() - 1;
		while(l <= r){
			int mid = l + (r - l) / 2;
			if(arr[mid] == tar)
				r = mid - 1;
			else if(arr[mid] > tar){
				r = mid - 1;
			}
			else if(arr[mid] < tar){
				l = mid + 1;
			}
		}
		if(l == arr.size())
			return INT_MAX;
		else if(l == 0)
			return INT_MAX;
		if(arr[l] == tar)
			return l;
		else{
			return tar - arr[r] <= arr[l] - tar? r: l; 
		}
	}
};

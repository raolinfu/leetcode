#include<vector>
#include<cmath>
#include<string>
#include<iostream>

using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
		if(chars.size() == 1)
			return 1;
		string str;
		char pre = chars[0];
		int cnt = 1;
		int idx = 0;
		for(int i = 1; i < chars.size(); i++){
			if(chars[i] != pre && cnt == 1){
				chars[idx] = pre;
				pre = chars[i];
				idx++;
			}
			else if(chars[i] != pre && cnt > 1){
				chars[idx++] = pre;
				int mod = pow(10, std::to_string(cnt).length());
				while(mod >= 1){
					chars[idx++] = cnt / mod + '0';
					cnt = cnt % mod;
					mod /= 10;
				}
				cnt = 1;
				pre = chars[i];
			}else{
				cnt++;
			}
		}
		if(cnt == 1){
			chars[idx] = pre;
			idx++;
		}
		else if(cnt > 1){
			chars[idx++] = pre;
			int mod = pow(10, std::to_string(cnt).length());
			while(mod >= 1){
				chars[idx++] = cnt / mod + '0';
				cnt = cnt % mod;
				mod /= 10;
			}
		}

		return idx;
    }
};

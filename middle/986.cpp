#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
		 int n=firstList.size(),m=secondList.size();
        vector<vector<int>> v;
        for(int i=0,j=0;i<n && j<m;){
            if(firstList[i][1]<secondList[j][0]){
                i++;
            }
            else if(firstList[i][0]>secondList[j][1]){
                j++;
            }
            else{
                v.push_back({max(firstList[i][0],secondList[j][0]),firstList[i][1]>secondList[j][1]?secondList[j++][1]:firstList[i++][1]});
            }
        }
        return v;
	}
};

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> map;
        map[0] = 0;
        for(auto rod :rods) {
            unordered_map<int, int> tmp(map);
            for(auto it : tmp) {
                int key = it.first;
                map[key + rod] = max(map[key + rod], tmp[key] + rod);
                map[key - rod] = max(map[key - rod], tmp[key]);
            }
        }
        return map[0];
    }
};

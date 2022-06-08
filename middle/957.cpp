#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<int, vector<int>> map;    //存储数据，key：第i天 value：cells状态
        map.insert({0, cells});  //存储牢房初始状态（第0天）
        for (int i = 1; i <= n; i++) {
            if (i == 1) {   //第一天时，首尾牢房没有两个相邻牢房，状态设为0
                cells[0] = 0;
                cells[7] = 0;
            }
            for (int j = 1; j < 7; j++) {   //修改2~7号牢房的状态（牢房号1 ~ 8，对应下标0 ~ 7）
                if (map[i - 1][j - 1] == 0 && map[i - 1][j + 1] == 0) cells[j] = 1;
                else if (map[i - 1][j - 1] == 1 && map[i - 1][j + 1] == 1) cells[j] = 1;
                else cells[j] = 0;
            }
            map.insert({i, cells});  //存储第i天牢房的的状态
            bool flag = true;
            for (int j = 0; j < 8; j++) {   //看是否与第一天的状态相同，相同则说明出现了循环
                if (cells[j] != map[1][j]) flag = false;   
            }
            if (i > 1 && flag) {    //出现循环，周期为i - 1，直接返回map中对应的值
                if (n % (i - 1) == 0) return map[i - 1];    //能整除则返回上一天的状态（余数为0）
                else return map[n % (i - 1)];   //不能整除时返回第 n % (i - 1) 的状态
            }
        }

        return cells;   //没出现循环直接返回模拟的结果
    }
};

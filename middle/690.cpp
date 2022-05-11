#include <vector>
#include <unordered_map>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans;
        unordered_map<int, Employee*> mp;
        for (auto e: employees) {
            mp.insert({e->id, e});
        }
        
        return getAns(mp, id);
    }

    int getAns(unordered_map<int, Employee*>& mp, int id) {
        int ans = mp[id]->importance;

        for (auto i: mp[id]->subordinates) {
            ans += getAns(mp, i);
        }

        return ans;
    }

};

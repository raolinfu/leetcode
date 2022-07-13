#include <unordered_map>
#include <list>
using namespace std;
class LRUCache {
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> li;
    int cnt;

public:
    LRUCache(int capacity) {
        cnt = capacity;
    }
    
    int get(int key) {
        if (!mp.count(key))
            return -1;

        auto p = *mp[key];
        li.erase(mp[key]);
        li.insert(li.begin(), p);
        mp[key] = li.begin();

        return li.begin()->second;
    }
    
    void put(int key, int value) {
        if (li.size() < cnt) {
            if (mp.count(key)) {
                li.erase(mp[key]);
            }

            li.emplace_front(key, value);
            mp[key] = li.begin();
        } else {
            if (!mp.count(key)) {
                mp.erase(li.back().first);
                li.pop_back();
                li.emplace_front(key, value);
                mp[key] = li.begin();
            } else {
                li.erase(mp[key]);
                li.emplace_front(key, value);
                mp[key] = li.begin();
            }
        }
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

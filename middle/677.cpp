#include <string>
#include <queue>
using namespace std;

struct Tire {
    bool isEnd;
    int val;
    Tire* children[26] = {nullptr};
    Tire(): isEnd(false), val(0) {};

    void insert(string& key, int& val) {
        Tire* cur = this;
        for (int i = 0; i < key.size(); i++) {
            int idx = key[i] - 'a';
            if (cur->children[idx]) {
                cur = cur->children[idx];
            } else {
                Tire* node = new Tire();
                cur->children[idx] = node;
                cur = node;
            }
        }

        cur->val = val;
        cur->isEnd = true;
    }

    Tire* getTire(string& str) {
        Tire* cur = this;
        for (int i = 0; i < str.length(); i++) {
            int idx = str[i] - 'a';
            if (cur->children[idx]) {
                cur = cur->children[idx];
            } else {
                cur = nullptr;
                break;
            }
        }

        return cur;
    };

};

class MapSum {
private:
    Tire root;
public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        root.insert(key, val);
    }
    
    int sum(string prefix) {
        Tire* cur = root.getTire(prefix);
        return getSum(cur);
    }

    int getSum(Tire* n) {
        int ans = 0;
        if (n == nullptr)
            return ans;
        queue<Tire*> que;
        que.push(n);
        while (!que.empty()) {
            auto f = que.front();
            que.pop();
            if (f->isEnd)
                ans += f->val;
            for (int i = 0; i < 26; i++) {
                if (f->children[i])
                    que.push(f->children[i]);
            }
        }

        return ans;
    }
};

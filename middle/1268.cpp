#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct Tire {
    bool isEnd;
    Tire* children[26] = {nullptr};
    Tire(): isEnd(false) {};

    void insert(string& str) {
        int i = 0;
        Tire* cur = this;
        while ( i < str.length() && cur->children[str[i] - 'a']) {
            cur = cur->children[str[i] - 'a'];
            i++;
        }

        while (i < str.length()) {
            Tire* n = new Tire();
            cur->children[str[i] - 'a'] = n;
            cur = n;
            i++;
        }

        cur->isEnd = true;
    }

    Tire* search(string& str) {
        Tire* cur = this;
        int i = 0;
        while (i < str.length() &&  cur->children[str[i] - 'a']) {
            cur = cur->children[str[i] - 'a'];
            i++;
        }

        return i == str.length()? cur: nullptr;
    }

};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        Tire root;
        for (auto& str: products)
            root.insert(str);
        for (int i = 1; i <= searchWord.length(); i++) {
            vector<string> res;
            string str = searchWord.substr(0, i);
            Tire* n = root.search(str);
            walk(n, str, res);

            ans.emplace_back(std::move(res));
        }

        return ans;
    }

    void walk(Tire* root, string& str, vector<string>& res) {
        if (root == nullptr || res.size() == 3)
            return;
        if (root->isEnd)
            res.emplace_back(str);
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                str += ('a' + i);
                walk(root->children[i], str, res);
                str.pop_back();
            }
        }
    }
};




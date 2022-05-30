#include <string>
#include <queue>
using namespace std;
struct Trie {
    bool isEnd = false;
    Trie* children[26] = {nullptr};

    void insert(string& str) {
        Trie* cur = this;
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            int idx = ch - 'a';
            if (cur->children[idx]) {
                cur = cur->children[idx];
            } else {
                Trie* n = new Trie();
                cur->children[idx] = n;
                cur = n;
            }
        }

        cur->isEnd = true;
    }
};

class WordDictionary {
private:
    Trie trie;
public:
    WordDictionary() {

    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return backtrace(&trie, 0, word);
/*         queue<pair<Trie*, int>> que;
 *         que.push({&trie, 0});
 *
 *         while (!que.empty()) {
 *             auto f = que.front();
 *             que.pop();
 *             Trie* cur = f.first;
 *             int idx = f.second;
 *             if (idx == word.size() && cur->isEnd)
 *                 return true;
 *             else if (idx == word.size())
 *                 continue;
 *
 *             if (word[idx] != '.') {
 *                 int j = word[idx] - 'a';
 *                 if (cur->children[j]) {
 *                     que.push({cur->children[j], idx + 1});
 *                 }
 *             } else {
 *                 for (int i = 0; i < 26; i++) {
 *                     if (cur->children[i]) {
 *                         que.push({cur->children[i], idx + 1});
 *                     }
 *
 *                 }
 *             }
 *         }
 *
 *         return false; */
    }

    bool backtrace(Trie* cur, int idx, string& word) {
        if (idx == word.size() && cur->isEnd)
            return true;
        else if (idx == word.size())
            return false;

        if (word[idx] != '.') {
            int j = word[idx] - 'a';
            if (cur->children[j]) {
                return backtrace(cur->children[j], idx + 1, word);
            }
        } else {
            for (int i = 0; i < 26; i++) {
                if (cur->children[i]) {
                    if (backtrace(cur->children[i], idx + 1, word))
                        return true;
                }
            }
        }

        return false;
    }
};

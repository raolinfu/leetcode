#include <string>
using namespace std;

class Trie {
public:
    bool isEnd;
    Trie* children[26];

    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
    
    void insert(string word) {
        Trie* cur = this;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
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
    
    bool search(string word) {
        Trie* cur = this;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (cur->children[idx]) {
                cur = cur->children[idx];
            } else {
                return false;
            }
        }

        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            int idx = ch - 'a';
            if (cur->children[idx]) {
                cur = cur->children[idx];
            } else {
                return false;
            }
        }

        return true;
    }
};

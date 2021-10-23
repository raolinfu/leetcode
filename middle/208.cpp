#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Trie {
private:
	string word;
	unordered_map<char, Trie*> children;
	Trie* searchPrefix(string prefix){
		Trie *node = this;
		for(auto ch: prefix){
			if(node->children.count(ch))
				node = node->children[ch];
			else
				return nullptr;
		}

		return node;
	}
public:
    Trie() {
		this->word = "";
    }
    
    void insert(string word) {
		Trie *node = this;
		for(auto ch: word){
			if(node->children[ch] == nullptr){
				node->children[ch] = new Trie();	
			}
			node = node->children[ch];
		}
		node->word = word;
	}
    
    bool search(string word) {
		Trie* node = searchPrefix(word);
		return node != nullptr && node->word == word;
    }
    
    bool startsWith(string prefix) {
		Trie *node = searchPrefix(prefix);
		return node == nullptr? false: true;
    }

};

int main(){
	return 0;
}

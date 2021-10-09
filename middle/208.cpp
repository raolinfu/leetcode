#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

struct Word{
	char ch;
	bool isEnd;
	vector<Word*> next;
	Word(char c):ch(c), next(26, nullptr), isEnd(false){
	}
};

class Trie {
public:
    Trie() {

    }
    
    void insert(string word) {
		if(word.empty())
			return;
		if(mp.find(*word.begin()) == mp.end())
		{	
			Word *head = new Word(*word.begin());
			mp.insert({*word.begin(), head});
			for(auto i = 1; i < word.length(); i++){
				Word *tmp = new Word(word[i]);
				head->next[word[i] - 'a'] = tmp;
				head = tmp;
				if(i == word.length() - 1)
					tmp->isEnd = true;
			}
		}else{
			Word *head = mp[word[0]];
			int i = 1;
			while(head->next[word[i] - 'a']){
				if(i == word.length() - 1)
				{
					head->isEnd = true;
					return;
				}
				head = head->next[word[i] - 'a'];
				i++;
			}
			while(i < word.length()){
				Word *tmp = new Word(word[i]);
				head->next[word[i] - 'a'] = tmp;
				head = tmp;
				if(i == word.length() - 1)
					tmp->isEnd = true;
			}
		}
	}
    
    bool search(string word) {
		if(word.empty())
			return false;
		if(mp.find(word[0]) == mp.end())
			return false;
		else{
			Word *head = mp[word[0]];
			int i = 1;
			head = head->next[word[i] - 'a'];
			while(head && head->ch == word[i]){
				if(i == word.length() - 1 && head->isEnd)
					return true;
				head = head->next[word[i] - 'a'];
				i++;
			}
		}

		return false;
    }
    
    bool startsWith(string prefix) {
		if(prefix.empty())
			return false;
		if(mp.find(prefix[0]) == mp.end())
			return false;
		else{
			Word *head = mp[prefix[0]];
			for(int i = 0; i < prefix.length(); i++){
				if(head && prefix[i] == head->ch)
				{
					head = head->next[prefix[i] - 'a'];
					continue;
				}
				return false;
			}
		}

		return true;
    }

private:
	map<char, Word*> mp;
};

int main(){
	vector<int> nums(61);
	Trie trie;
	trie.insert("rao");
	bool res = trie.search("rao");

	return 0;
}

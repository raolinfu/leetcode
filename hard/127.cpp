#include <string>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> used;
		unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_set<string> visited;
		queue<string> q;
		int d = 0;
		q.push(beginWord);

        if (!words.count(endWord))
            return 0;
		while (!q.empty()) {
			int n = q.size();
            visited.clear();
			for (int i = 0; i < n; i++) {
				string word = q.front();
				q.pop();
				if (word == endWord) {
					return d;
				}
				for (int i = 0; i < word.length(); i++) {
					char t = word[i];
					for (char ch = 'a'; ch <= 'z'; ch++) {
						used.insert(word);
						word[i] = ch;
						// word not used and is in list
						if (words.count(word) && !used.count(word)) {
                            visited.insert(word);
							q.push(word);
						}
					}
					word[i] = t;
				}
			}
		}

		return 0;
};
};

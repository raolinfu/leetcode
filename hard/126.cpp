#include <string>
#include <queue>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> ans;
		unordered_set<string> used;
		unordered_set<string> words(wordList.begin(), wordList.end());
		vector<string> tmp;
        if (!words.count(endWord))
            return ans;
		/* tmp.push_back(beginWord);
		 * used.insert(beginWord); */
		words.insert(beginWord);
		dfs(ans, tmp, used, words, beginWord, endWord);
		return ans;
    }

	// 深度优先遍历 超时 指数爆炸
	void dfs(vector<vector<string>>& ans, 
			vector<string>& tmp, 
			unordered_set<string>& used, 
			unordered_set<string>& words, 
			string word, 
			string& endWord) {
		cout<< "------------word:"<< word<< endl;
		if (word == endWord) {
			tmp.push_back(word);
			if (ans.empty() || ans[0].size() == tmp.size()) {
				ans.push_back(tmp);
			} else if (ans[0].size() > tmp.size()) {
				ans.clear();
				ans.push_back(tmp);
			}
			tmp.pop_back();
			return;
		}

		if (!words.count(word) || used.count(word)) {
			return;
		}

		used.insert(word);
		tmp.push_back(word);

		for (int i = 0; i < word.length(); i++) {
			char t = word[i];
			for (char ch = 'a'; ch <= 'z'; ch++) {
				if (ch == word[i])
					continue;
				word[i] = ch;
				cout<< "replace word:"<< word<< endl;
				dfs(ans, tmp, used, words, word, endWord);
			}
			word[i] = t;
		}

		tmp.pop_back();
		used.erase(word);
	}

    vector<vector<string>> findLadders1(string beginWord, string endWord, vector<string>& wordList) {

		vector<vector<string>> ans;
		unordered_set<string> used;
		unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_set<string> visited;
		vector<string> tmp{beginWord};
		bool flag = true;
        if (!words.count(endWord))
            return ans;
		queue<vector<string>> q;
		q.push(tmp);
		while (!q.empty() && flag) {
			int n = q.size();
            visited.clear();
           // cout<< "----------size:"<< n<< endl;
			for (int i = 0; i < n; i++) {
				tmp = q.front();
				q.pop();

				string word = tmp.back();
				if (word == endWord) {
					flag = false;
					ans.push_back(tmp);
					continue;
				}
				for (int i = 0; i < word.length(); i++) {
					char t = word[i];
					for (char ch = 'a'; ch <= 'z'; ch++) {
						if (ch == word[i])
							continue;
						word[i] = ch;
						// word not used and is in list
						if (words.count(word) && !used.count(word)) {
                            visited.insert(word);
							vector<string> cur = tmp;
							cur.push_back(word);

							q.push(cur);
						}
					}
					word[i] = t;
				}
			}
			// 对于同有层的节点，需要再这曾遍历完后将访问过的节点放入used里
            for (auto word: visited)
				used.insert(word);
		}

		return ans;
    }
};

int main() {

	string beginWord = "qa";
	string endWord = "sq";
	vector<string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
	Solution sol;
	sol.findLadders(beginWord, endWord, wordList);
	return 0;
}

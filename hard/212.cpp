#include<string>
#include<unordered_set>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
struct Tree{
	string word;
	bool isEnd;
	unordered_map<char, Tree*> mp;
	Tree(): isEnd(false){};
	void insert(string s){
		Tree* cur = this;
		for(char ch: s){
			if(!cur->mp.count(ch)){
				cur->mp[ch] = new Tree();
			}
			cur = cur->mp[ch];
		}
		cur->isEnd = true;
		cur->word = s;
	}

	Tree* search(char ch){
		// if(mp.find(ch) != mp.end()){
		if(mp.count(ch)){
			return mp[ch]; 
		}
		return nullptr;
	}
};

void process(vector<vector<char>>& board, vector<vector<bool>>& visit, unordered_set<string>& res, Tree* node, int i, int j, int rows, int cols);
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	unordered_set<string> res;
	vector<vector<bool>> visit(board.size(), vector<bool>(board[1].size(), true));
	Tree tree;
	int rows = words.size();
	int cols = words[0].size();
	for(string w: words){
		tree.insert(w);
	}
	for(int i = 0; i < words.size(); i++){
		for(int j = 0; j < words[0].size(); j++){
			process(board, visit, res, &tree, i, j, rows, cols);
		}
	}

	return res.size()? vector<string>(res.begin(), res.end()): vector<string>();
}

void process(vector<vector<char>>& board, vector<vector<bool>>& visit, unordered_set<string>& res, Tree* node, int i, int j, int rows, int cols){
	if(i >=0 && i < rows && j >=0 && j < cols && visit[i][j] ){
		Tree* cur = node->search(board[i][j]);
		if(cur){
			if(cur->isEnd && !res.count(cur->word)){
				res.insert(cur->word);
			}
			visit[i][j] = false;
			process(board, visit, res, cur, i + 1, j, rows, cols);
			process(board, visit, res, cur, i - 1, j, rows, cols);
			process(board, visit, res, cur, i, j + 1, rows, cols);
			process(board, visit, res, cur, i, j - 1, rows, cols);
			visit[i][j] = true;;
		}		
	}


}

int main(){
	/* vector<vector<char>> board =   {{'o','a','a','n'},
	 *                                 {'e','t','a','e'},
	 *                                 {'i','h','k','r'},
	 *                                 {'i','f','l','v'}};
	 * vector<string>words = {"oath","pea","eat","rain"}; */
	vector<vector<char>> board = {{'a','b'},{'c','d'}};
	vector<string> words = {"abcb"};
	vector<string> res = findWords(board, words);
	for(auto str: res)
		cout<< str<< endl;
	return 0;
}

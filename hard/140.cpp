// 单词拆分
#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct TreeNode{
	bool isEnd;	
	unordered_map<char, TreeNode*> children;
	TreeNode(){
		isEnd = false;
	}
	void insert(string s){
		TreeNode *node = this;
		for(auto ch: s){
			if(node->children.count(ch) == 0)
				node->children[ch] = new TreeNode();
			node = node->children[ch];
		}
		node->isEnd = true;
	}
	TreeNode* search(char ch, TreeNode* node){
		return	node->children.find(ch) == node->children.end()? nullptr: node->children[ch]; 
	}
};

void process(string &s, TreeNode &tree, vector<string> &res, string cur, int idx);
vector<string> wordBreak(string s, vector<string>& wordDict) {
	vector<string> res;
	TreeNode tree;
	string cur;
	for(auto str: wordDict){
		tree.insert(str);
	}
	process(s, tree, res, cur, 0);

	return res;
}

void process(string &s, TreeNode &tree, vector<string> &res, string cur, int idx){
	if(idx == s.length())
		res.push_back(cur);
	TreeNode *node = tree.search(s[idx], &tree);
	int step = 1;
	while(idx + step <= s.length()){
		if(node == nullptr)
			return;
		else if(node->isEnd){
			cout<< "substr: "<< s.substr(idx, step)<< endl;
			string tmp = cur == ""? s.substr(idx, step): cur + " " + s.substr(idx, step);
			process(s, tree, res, tmp, step + idx);
		}
		node = node->children[s[idx + step]];
		step++;
	}

}

int main(){
	/* string s = "catsanddog";
	 * vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"}; */
	string s = "pineapplepenapple";
	vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
	vector<string> res = wordBreak(s, wordDict);
	for(int i = 0; i < res.size(); i++){
		cout<< res[i]<< endl;
	}
	return 0;
}

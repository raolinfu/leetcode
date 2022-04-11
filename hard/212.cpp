#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
class Tire {
    public:
        bool isEnd = false;
        Tire* childreen[26] = {nullptr};

        void insert(string& str) {
            Tire* cur = this;
            for (char ch: str) {
                if (cur->childreen[ch - 'a']) {
                    cur = cur->childreen[ch - 'a'];
                } else {
                    Tire* n = new Tire();
                    cur->childreen[ch - 'a'] = n;
                    cur = n;
                }
            }
            cur->isEnd = true;
        };
};

class Solution {
private:
    int rows;
    int cols;
    unordered_set<string> st;
    Tire* root;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        root = new Tire();
        for (auto& w: words)
            root->insert(w);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                string tmp;
                backtrace(board, tmp, root, i , j, visited);
            }
        }

        return vector<string>(st.begin(), st.end());
    }

    void backtrace(vector<vector<char>>& board, string& tmp, Tire* cur, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j])
            return;
        char& ch = board[i][j];
        Tire* child = cur->childreen[ch - 'a'];
        if (child == nullptr)
            return;
        visited[i][j] = true;
        tmp += ch;
        if (child->isEnd)
            st.insert(tmp);
        backtrace(board, tmp, child, i + 1, j, visited);
        backtrace(board, tmp, child, i - 1, j, visited);
        backtrace(board, tmp, child, i, j + 1, visited);
        backtrace(board, tmp, child, i, j - 1, visited);

        tmp.pop_back();
        visited[i][j] = false;
    }
};














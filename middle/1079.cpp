#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    unordered_set<string> st;
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        vector<bool> visited(n, false);
        string str;

        for (int i = 0; i < tiles.size(); i++) {
            str.push_back(tiles[i]);
            visited[i] = true;
            backtrace(tiles, visited, str, 1);
            str.pop_back();
            visited[i] = false;
        }

        return st.size();
    }

    void backtrace(string& tiles, vector<bool>& visited, string& str, int idx) {
        st.insert(str);

        if (idx == tiles.size()) {
            st.insert(str);
            return;
        }

        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                str.push_back(tiles[i]);
                backtrace(tiles, visited, str, idx + 1);
                str.pop_back();
                visited[i] = false;
            }
        }
    }
};

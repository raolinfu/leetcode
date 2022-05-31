#include<vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<bool> visited(numCourses, false);
        vector<bool> walked(numCourses, false);

        for (auto& v: prerequisites) {
            graph[v[1]].push_back(v[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!backtrace(graph, visited, walked, i))
                return false;
        }

        return true;
    }

    bool backtrace(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& walked, int i) {
        if (visited[i])
            return false;
        if (walked[i])
            return true;
        visited[i] = true;
        for (auto j: graph[i]) {
            if (!backtrace(graph, visited, walked, j)) {
                return false;
            }
        }

        visited[i] = false;
        walked[i] = true;
        return true;
    }
};

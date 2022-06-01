#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    vector<int> ans;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<bool> visited(numCourses, false);
        vector<bool> walked(numCourses, false);
        vector<bool> isBegin(numCourses, true);

        for (auto& v: prerequisites) {
            graph[v[1]].push_back(v[0]);
            isBegin[v[0]] = false;
        }

        for (int i = 0; i < numCourses; i++) {
            if (!backtrace(graph, visited, walked, i))
                return {};
        }

        for (int i = 0; i < walked.size(); i++)
            walked[i] = false;

        for (int i = 0; i < isBegin.size(); i++) {
            if (isBegin[i]) {
                getAns(graph, walked, i);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
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

    void getAns(vector<vector<int>>& graph, vector<bool>& walked, int i) {
        if (walked[i])
            return;

        walked[i] = true;
        for (auto j: graph[i]) {
            getAns(graph, walked, j);
        }
        ans.push_back(i);
    }
};


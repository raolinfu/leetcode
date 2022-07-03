#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<vector<int>> ans(m, vector<int>(n));
         int x1 = 0, y1 = 0;
         int x2 = m - 1, y2 = n - 1;
         while (x1 <= x2 && y1 <= y2) {
             for (int j = y1; j <= y2; j++) {
                 ans[x1][j] = head? head->val: -1;
                 head = head? head->next: head;
             }

             for (int i = x1 + 1; i <= x2; i++) {
                 ans[i][y2] = head? head->val: -1;
                 head = head? head->next: head;
             }

             for (int j = y2 - 1; x2 > x1 && j >= y1; j--) {
                 ans[x2][j] = head? head->val: -1;
                 head = head? head->next: head;
             }

             for (int i = x2 - 1; y2 > y1 && i >= x1 + 1; i--) {
                 ans[i][y1] = head? head->val: -1;
                 head = head? head->next: head;
             }
             
             ++x1;
             ++y1;
             --x2;
             --y2;
         }

         return ans;
    }
};

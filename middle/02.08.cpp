#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> un_st;
        while (head)
        {
            if (un_st.count(head))
                return head;
            un_st.insert(head);
            head = head->next;
        }
        
        return nullptr;
    }
};
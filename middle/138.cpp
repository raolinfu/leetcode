#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, int> mp2;
        unordered_map<int, Node*> mp;
        Node dumpy(0);
        Node* pre = &dumpy;
        Node* cur = head;
        int i = 1;
        while (cur) {
            Node* next = new Node(cur->val);
            pre->next = next;
            pre = next;

            mp2.insert({cur, i});
            mp.insert({i, pre});

            i++;
            cur = cur->next;
        }

        cur = head;
        Node* cur1 = dumpy.next;
        while (cur) {
            cur1->random =  mp[mp2[cur->random]];
            cur = cur->next;
            cur1 = cur1->next;
        }
        
        return dumpy.next;
    }
};

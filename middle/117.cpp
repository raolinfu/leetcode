
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;

        Node* start = root;
        while (start) {
            Node* nextStart = nullptr;
            Node* last = nullptr;
            for (Node* p = start; p != nullptr; p = p->next) {
                if (p->left)
                    handle(last, p->left, nextStart);
                if (p->right)
                    handle(last, p->right, nextStart);
            }

            start = nextStart;
        }
        
        return root;
    }

    void handle(Node* &last, Node* &cur, Node* &nextStart) {
        if (last) {
            last->next = cur;
        }

        if (!nextStart) {
            nextStart = cur;
        }

        last = cur;
    }
};

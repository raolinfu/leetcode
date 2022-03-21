#include <queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
		if (root == nullptr)
			return root;
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node* pre = q.front();
			int len = q.size();
			if (pre->left)
				q.push(pre->left);
			if (pre->right)
				q.push(pre->right);
			q.pop();
			int i = 1;
			for (; i < len; i++) {
				Node* cur = q.front();
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
				pre->next = cur;
				pre = cur;
				q.pop();
			}
			if (i == len)
				pre->next = nullptr;
		}

		return root;
    }
};

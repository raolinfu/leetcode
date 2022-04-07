struct Node{
	int val;
	Node* next;
	Node(int value): val(value), next(nullptr){};
};

class MyLinkedList {
public:
    MyLinkedList() {
		head = nullptr;
		tail = nullptr;
		len = 0;
    }
    
    int get(int index) {
		if (index >= len || index < 0)
			return -1;
		Node* cur = head;
		while (index) {
			cur = cur->next;
			index--;
		}

		return cur->val;
    }
    
    void addAtHead(int val) {
		if (len == 0) {
			head = new Node(val);
			tail = head;
			len++;
			return;
		}
		Node* cur = new Node(val);
		cur->next = head;
		head = cur;
		len++;
    }
    
    void addAtTail(int val) {
		if (len == 0) {
			tail = new Node(val);
			head = tail;
			len++;
			return;
		}
		Node* cur = new Node(val);
		tail->next = cur;
		tail = cur;
		len++;
    }
    
    void addAtIndex(int index, int val) {
		if (index > len) {
			return;
		}
		else if (index <= 0) {
			Node* cur = new Node(val);
			cur->next = head;
			head = cur;
			len++;
			return;
		}
		else if (index == len) {
			Node* cur = new Node(val);
			tail->next = cur;
			tail = cur;
			return;
		}
		Node* n = head;
		while (index > 1) {
			n = n->next;
			index--;
		}

		Node* next = n->next;
		n->next = new Node(val);
		n->next->next = next;
		len++;
    }
    
    void deleteAtIndex(int index) {
		if (index >= len || index < 0) {
			return;
		}
		else if (index == 0) {
			Node* next = head->next;
			delete head;
			head = next;
			len--;
			return;
		}
		Node* n = head;
		while(index > 1) {
			n = n->next;
			index--;
		}
		Node* next = n->next;
		if (next->next) {
			n->next = next->next;
			delete next;
		} else {
			n->next = next->next;
			delete next;
			tail = n->next;
		}
		len--;
    }
private:
	Node* head;
	Node* tail;
	int len;
};

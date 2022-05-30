#include <sys/mman.h>
#include <string.h>
#include <vector>
#include <mutex>
#include <iostream>
using namespace std;
// 0x08048000
// 00400000
struct Node {
	int key_;
	int val_;
	Node* next_ = nullptr;
};

/* class Look {
 *     private:
 *         int nums[10];
 *         mutex lock;
 *     public:
 *         void init() {
 *         };
 * }; */

class Allocator {
	private:
		void* base;
		Node* node_start_;
		Node freeHead_;
		uint32_t freeCnt_;
		uint32_t size_;
		mutex lock_;

	public:
		Allocator(uint32_t size) {
			size_ = size;
			// unsigned long addr = 0x00200000;
			unsigned long addr = 0x200000;
			size_t len = 0x20000;
			base =  mmap(&addr, len, 0x1 | 0x2 | 0x4,  0x02 | 0x20, -1, 0);
			cout<< "base:"<< base<< endl;
			if (errno != 0) {
				cout<< "mmap failed"<< endl;
				exit(-1);
			}
			node_start_ = (Node*)base ;
			for (int i = 0; i < size_; i++) {
				node_start_[i].next_ = freeHead_.next_;
				freeHead_.next_ = &node_start_[i];
				/* if (freeCnt_ == 0) {
				 *     freeHead_.next_ = &node_start_[i];
				 * } else {
				 *     node_start_[i].next_ = freeHead_.next_;
				 *     freeHead_.next_ = &node_start_[i];
				 * } */
			}
			freeCnt_ = size;
		};

		Node* GetNode() {
			Node* res;
			if (freeCnt_ == 0)
				return nullptr;
			lock_.lock();
			res = freeHead_.next_;
			freeHead_.next_ = res->next_;
			res->next_ = nullptr;
			freeCnt_--;
			lock_.unlock();
			return res;
		}

		void FreeNode(Node* n) {
			lock_.lock();
			*n = {0};
			n->next_ = freeHead_.next_;
			freeHead_.next_ = n;
			/* if (freeCnt_ == 0) {
			 *     n->next_ = nullptr;
			 *     freeHead_.next_ = n;
			 * } else {
			 *     n->next_ = freeHead_.next_;
			 *     freeHead_.next_ = n;
			 * } */
			freeCnt_++;
			lock_.unlock();
		}
		
		uint32_t GetSize() {
			return size_;
		}

		uint32_t GetFree() {
			return freeCnt_;
		}

		void DisplayFree() {
			Node* cur = freeHead_.next_;
			int i = 0;
			while (cur) {
				cout<< i<< "\t"<< cur->key_<< "\t"<< cur->val_<< endl;
				cur = cur->next_;
				i++;
			}
		}
};


int main() {

	vector<Node*> nodes;
	unsigned long addr = 0x0000000080000000;
	size_t len = 0x2000000;
	void* start =  mmap(&addr, len, 0x1 | 0x2 | 0x4,  0x02 | 0x20, -1, 0);
	if (errno != 0) {
		cout<< "failed"<< endl;
		exit(-1);
	}

	// Allocator allocator(100);
	Allocator allocator(1 << 20);
	cout<< allocator.GetSize()<< endl;
	// allocator.DisplayFree();


	for (int i = 0; i < 1<<21; i++) {
		Node* cur = allocator.GetNode();
		if (cur == nullptr) {
			cout<< i<< "\tnullptr node"<< endl;
			continue;
		}
		cout<< i<< "\t get node success  "<< allocator.GetSize()<< "\t"<< allocator.GetFree()<< endl;
		nodes.push_back(cur);
	}

	for (int i = 0; i < nodes.size(); i++) {
		allocator.FreeNode(nodes[i]);
		cout<< i<< "\t free node success  "<< allocator.GetSize()<< "\t"<< allocator.GetFree()<< endl;
	}

/*     Node* head = allocator.GetNode();
 *     Node* n1 = allocator.GetNode();
 *     Node* n2 = allocator.GetNode();
 *     head->next_ = n1;
 *     head->key_ = 22;
 *     head->val_ = 22;
 *
 *     n1->next_ = n2;
 *     n1->key_ = 12;
 *     n1->val_ = 12;
 *
 *     n2->next_ = nullptr;
 *     n2->key_ = 13;
 *     n2->val_ = 13; */

/*     Node* cur = head;
 *     while (cur) {
 *         cout<< cur->key_<< "\t"<< cur->val_<< endl;
 *         cur = cur->next_;
 *     }
 *
 *     allocator.FreeNode(head);
 *     allocator.FreeNode(n1);
 *     allocator.FreeNode(n2); */
	// allocator.DisplayFree();

	return 0;
}

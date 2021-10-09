#include<iostream>
using namespace std;

struct node{
	int v;
	node *next;
	node(int a): v(a), next(nullptr){}
};

int main(){
	node *head = new node(12);
	node *tmp = new node(13);
	head->next = tmp;
	tmp->next = new node(14);
	return 0;
}

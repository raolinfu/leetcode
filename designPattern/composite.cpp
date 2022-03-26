#include "composite.h"
void Corp::showInfo() {
	cout<< "name:"<< name<< "\tsalary:"<< salary<< endl;
}

void Manager::addChild(Corp* child) {
	this->children.push_back(child);
};

vector<Corp*> Manager::getChildren() {
	return this->children;
}

void Manager::showAll() {
	this->showInfo();
	for (auto e: children) {
		e->showInfo();
	}
	cout<< endl;
}

int main() {
	Manager* root = new Manager("lisi", 20000);

	Manager* manager1 = new Manager("zhangsan", 16000);
	Manager* manager2 = new Manager("wangba", 16700);
	root->addChild(manager1);
	root->addChild(manager2);
	root->showAll();

	manager1->showInfo();
	manager2->showInfo();
	delete root;
	delete manager1;
	delete manager2;
	return 0;
}

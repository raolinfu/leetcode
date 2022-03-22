#include <iostream>
using namespace std;
// 饿汉模式
class Emperor {
	public:
		~Emperor(){
				std::cout<<"destructor called!"<<std::endl;
			}
		// 禁止拷贝构造
		Emperor(const Emperor&) = delete;
		// 禁止赋值构造
		Emperor& operator=(const Emperor&) = delete;
		static Emperor& getEmperor();
		int getAge();

	private:
		Emperor() {
			std::cout<<"constructor called!"<<std::endl;
		};
		int age = 12;
};
Emperor& Emperor::getEmperor() {
	static Emperor one_emperor;
	return one_emperor;
}

// 懒汉模式

int Emperor::getAge() {
	return age;
}
int main() {
	Emperor& emp = Emperor::getEmperor();
	cout<< emp.getAge()<< endl;
	return 0;
}

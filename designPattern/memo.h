#ifndef MEMO_H
#define MEMO_H
class Memo1;
// 多状态
class Originator1 {
	private:
		int age;
		int salary;
	public:
		Originator1(int a, int s): age(a), salary(s) {};
		void setAge(int age) {this->age = age;};
		void setSalary(int s) {this->salary = s;};
		int getAge() { return this->age;};
		int getSalary() { return this->salary;};
		void restoreState(Memo1 memo1);
		Memo1 createState();
};

class Memo1 {
	private:
		int age;
		int salary;
	public:
		Memo1() = default;
		Memo1(int a, int s): age(a), salary(s) {};
		int getAge();
		int getSalary();
};

class CareTaker {
	public:
		void setMemoinfo(Memo1 m);
		Memo1 getMemoinfo();
	private:
		Memo1 memo1;
};

#endif

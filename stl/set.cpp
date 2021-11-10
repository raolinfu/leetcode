#include<set>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

struct stu{
	string name;
	int score;
};

int main(){
	auto comp = [](const struct stu &a, const struct stu &b){return a.score < b.score;};
	set<stu, decltype(comp)> s(comp);
	s.insert({"ad", 23});
	s.insert({"dd", 43});
	s.insert({"dkdd", 63});
	s.insert({"asdlfd", 93});
	for_each(s.begin(), s.end(), [](const struct stu &s){
		cout<< s.name<< "\t"<< s.score<< endl;
			});
	return 0;
}

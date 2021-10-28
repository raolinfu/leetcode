#include<unordered_map>
#include<set>
#include<algorithm>
#include<functional>
#include<iostream>
#include<map>

using namespace std;

int main(){
	unordered_map<int, int> un_map;
	un_map.rehash(3);
	un_map.insert({1, 3});
	un_map.insert({2, 323});
	un_map.insert({3422, 323});
	un_map.insert({9, 323});
	un_map.insert({34242, 323});
	un_map.insert({19, 323});
	un_map.insert({6, 323});
	for(auto iter = un_map.begin(); iter != un_map.end(); iter++){
		cout<< iter->first<< "  "<< iter->second<<endl;
	}
	cout<< un_map.bucket_count()<< endl;
	un_map.rehash(3);
	for(auto iter = un_map.begin(); iter != un_map.end(); iter++){
		cout<< iter->first<< "  "<< iter->second<<endl;
	}
	cout<< un_map.bucket_count()<< endl;

	// map<int, int, greater<int>> mp;
	// 用lambda表达式写比较函数
	cout<< "lambda表达式"<< endl;
	auto comp = [](const int &a, const int &b){return a < b;};
	map<int, int, decltype(comp)> mp(comp);
	mp.insert({12, 4});
	mp.insert({2, 4});
	mp.insert({312, 4});
	mp.insert({32, 4});
	for(auto iter = mp.begin(); iter != mp.end(); iter++){
		cout<< iter->first<< "  "<< iter->second<<endl;
	}
	return 0;
}

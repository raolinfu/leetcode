#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
	vector<int> res;
	int len = asteroids.size();
	int i = len - 1;
	while(i >= 0){
		if(res.empty()){
			res.push_back(asteroids[i]);
			i--;
			continue;

		}
		int back = res.back();
		if(res.back() > 0 || asteroids[i] < 0){
			res.push_back(asteroids[i]);
			i--;
		}
		else{
			if(asteroids[i] + back == 0){
				res.pop_back();
				i--;
			}else if(asteroids[i] + back > 0){
				res.pop_back();
			}else{
				i--;
			}
		}

	}

	std::reverse(res.begin(), res.end());
	return res;
}

int main(){
	vector<int> asteroids = {-2,2,-1,-2};
	// vector<int>asteroids = {5,10,-5};
	vector<int> res = asteroidCollision(asteroids);
	for(auto num: res){
		cout<< num<< " ";
	}
	cout<< endl;
	return 0;
}

#include<vector>
#include<stack>
#include<string>
#include<iostream>
#include<utility>
using namespace std;
/* 
 * 如果为start, 通过pre更新栈顶id的时间, 再进栈, 并更新pre为当前值 
 * 如果为end, 则出栈, 通过pre计算栈顶id的时间, 再出栈, 并更新pre为当前值
 * */
struct Ele{
	int id;
	int time;
	Ele(int id, int time){
		this->id = id;
		this->time = time;
	}
};

vector<int> exclusiveTime(int n, vector<string>& logs) {
	vector<int> ans(n, 0);
	stack<Ele> st;
	int pre = 0;
	bool pre_is_start = true;

	for(auto log: logs){
		int first = log.find_first_of(':');
		int second = log.find_last_of(':');
		int id = atoi(log.substr(0, log.find_first_of(':')).c_str());
		int ts = atoi(log.substr(second + 1, log.size() - 1 - second).c_str());
		string flag = log.substr(first + 1, second - first - 1);
		if(flag == "start"){
			if(!st.empty()){
				if(pre_is_start)
					st.top().time += (ts - pre);
				else
					st.top().time += (ts - pre - 1);
			}
			st.push(Ele(id, 0));
			pre = ts;
			pre_is_start = true;
		}else {
			if(pre_is_start)
				ans[st.top().id] += st.top().time + (ts - pre + 1);
			else
				ans[st.top().id] += st.top().time + (ts - pre);
			st.pop();
			pre = ts;
			pre_is_start = false;
		}
		
		cout<< id<< " "<< ts<<" "<< flag<< endl;;
	}

	return ans;
}
int main(){
	// vector<string> logs = {"0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"};
	/* int n = 2;
	 * vector<string>logs = {"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"}; */
	/* int n = 2;
	 * vector<string>logs = {"0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"}; */
	int n = 1;
	vector<string>logs = {"0:start:0","0:end:0"};
	vector<int> ans = exclusiveTime(n, logs);
	for(auto n : ans)
		cout<< n<< endl;
	return 0;
}

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
	private:
		int y;
		int m;
		int d;
		int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	public:
		Solution(int year, int month, int day): y(year), m(month), d(day) {};

		void helper() {
			if (m <= 0 || m > 12) {
				return;
			}

			int alldays = 0;
			for (int i = 1990; i < y; i++) {
				if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
					alldays += 366;
				} else {
					alldays += 365;
				}
			}

			for (int i = 1; i < m; i++) {
				alldays += months[i - 1];
				if (i == 2 && (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))) {
					alldays += 1;
				}
			}

			alldays += d;

			int res = alldays % 5;
			if (res <= 3 && res != 0)
				cout<< "working"<< endl;
			else
				cout<< "rest"<< endl;
		}
};

int main(){
	string line;
	getline(cin, line);
	istringstream record(line);
	string y;
	string m;
	string d;
	getline(record, y, '-');
	getline(record, m, '-');
	getline(record, d, '-');
	int year = stoi(y);
	int month = stoi(m);
	int day = stoi(d);
	cout<< year<< endl;
	cout<< month<< endl;
	cout<< day<< endl;
	Solution sol(year, month, day);
	sol.helper();

	return 0;
}

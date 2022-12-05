#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    string word;
	string years;
	string month;
	string day;
	getline(cin, line);
	istringstream record(line);
	getline(record, years, '-');
	getline(record, month, '-');
	getline(record, day, '-');
	int y = stoi(years);
	int m = stoi(month);
	int d = stoi(day);
	cout<< y<< endl;
	cout<< m<< endl;
	cout<< d<< endl;

	cout<< years<< endl;
	cout<< month<< endl;
	cout<< day<< endl;

	/*
    while (getline(cin, line))
    {
        istringstream record(line);
        // while (getline(record, word, ','))
        // {
        //     cout<< "word:"<< word<< endl;
        // }
        

        while (record>> word) {
            cout<< "word:"<< word<< endl;
        }
    }
	*/
    
    return 0;
}

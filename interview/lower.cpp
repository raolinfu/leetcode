#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    char ch;
    int arr[26]={0};
    getline(cin, str);
    cin>> ch;

    if(std::isupper(ch)) {
        ch += 32;
    }
    for (int i = 0; i < str.length(); i++) {
        if (std::isupper(str[i])) {
            ++arr[str[i] + 32 - 'a'];
        } else {
            ++arr[str[i] - 'a'];
        }
    }

    cout<< arr[ch - 'a']<< endl;
}
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
		int mp[26] = {0};
		bool isIn[26] = {0};

		for (auto ch: s) {
			mp[ch - 'a']++;
		}
		string str;
		for (auto ch: s) {
			if (str.empty() && isIn[ch - 'a'] == false) {
				str += ch;
				isIn[ch - 'a'] = true ;
			} 
			else if(isIn[ch - 'a'] == false){
				while (!str.empty() && ch < str.back() && mp[str.back() - 'a'] > 1) {
					mp[str.back() - 'a']--;
					isIn[str.back() - 'a'] = false;
					str.pop_back();
				}
				isIn[ch - 'a'] = true ;
				str.push_back(ch);
			} else {
				mp[ch - 'a']--;
			}
		}

		return str;
    }
};

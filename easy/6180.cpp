#include <string>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        int mp[26] = {0};
        int n = key.length();
        char p = 'a';
        for (int i = 0; i < n; i++) {
            if (key[i] == ' ')
                continue;
            if (p <= 'z') {
                int idx = key[i] - 'a';
                if (mp[idx] == 0) {
                    mp[idx] = p;
                    p++;
                }
            } else {
                break;
            }
        }

        for (int i = 0; i < message.size(); i++) {
            if (message[i] == ' ')
                continue;
            int idx = message[i] - 'a';
            message[i] = mp[idx];
        }
        
        return message;
    }
};

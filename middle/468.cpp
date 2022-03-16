#include <string>
using namespace std;
class Solution {
public:
    string validIPAddress(string queryIP) {
		string tmp;
		string ans1 = "Neither";
		string ans2 = "IPv4";
		string ans3 = "IPv6";
		int ipv6_cnt = 0;
		int ipv4_cnt = 0;
		for (auto ch: queryIP) {
			if (ch == '.')
				ipv4_cnt++;
			if (ch == ':')
				ipv6_cnt++;
		}
		if (ipv4_cnt && ipv6_cnt)
			return ans1;
		else if (ipv4_cnt && ipv4_cnt != 3)
			return ans1;
		else if (ipv6_cnt && ipv6_cnt != 7)
			return ans1;
		if (ipv4_cnt) {
			if (queryIP.back() == '.')
				return ans1;
			for (auto ch: queryIP) {
				if (tmp.empty() && ch == '.') {
					return ans1;
				} else if (ch == '.') {
					// 需要对长度判断一下
					if (tmp.size() >= 2 && tmp[0] == '0' || tmp.length() > 4) {
						return ans1;
					} 

					int n = std::atoi(tmp.c_str());
					if (n > 255)
						return ans1;
					tmp.clear();
				} else if (ch < '0' || ch > '9') {
					return ans1;
				}else {
					tmp += ch;
				}
			}
			// 最后是没有.的
			if (tmp.size() >= 2 && tmp[0] == '0') {
				return ans1;
			} 
			int n = std::atoi(tmp.c_str());
			if (n > 255)
				return ans1;

			return ans2;
		} else if(ipv6_cnt) {
			if (queryIP.back() == ':')
				return ans1;
			for (auto ch: queryIP) {
				if (tmp.empty() && ch == ':') {
					return ans1;
				} else if (ch == ':') {
					if (tmp.length() > 4)
						return ans1;
					tmp.clear();
				} else if (!(ch >= 'a' && ch <= 'f') 
						&& !(ch >= '0' && ch <= '9') 
						&& !(ch >= 'A' && ch <= 'F')) {
					return ans1;
				} else {
					tmp += ch;
				}
			}
			if (tmp.length() > 4)
				return ans1;

			return ans3;
		}
    return ans1;
    }
};

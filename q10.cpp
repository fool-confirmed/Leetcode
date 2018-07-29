#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() > 1 && p[1] == '*') {
			if (s[0] == p[0] || p[0] == '.') {
				//* is zero
				if (isMatch(s, p.substr(2))) return true;
				//* is not zero
				if (s.length() > 0 && isMatch(s.substr(1), p)) return true;
			}
			else {
				return p.length() >= 2 && isMatch(s, p.substr(2));
			}
		}
		else {
			if (s[0] == p[0] || (p[0] == '.' && !s.empty())) {
				s = s.length() > 1 ? s.substr(1) : "";
				p = p.length() > 1 ? p.substr(1) : "";
				return (s.length() == 0 && p.length() == 0) || isMatch(s, p);
			}
			else {
				return false;
			}
		}
		return false;
    }
};
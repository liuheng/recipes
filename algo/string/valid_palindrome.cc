#include <cctype>
#include <cstdio>
#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

inline bool pred(char a) {
    return isalnum(a) == 0;
}

bool isPalindrome(string s) {
    string str(s);
    str.erase(remove_if(str.begin(), str.end(), pred), str.end());
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    string rs("");
    rs.assign(str.rbegin(), str.rend());
    return str == rs;
}

int main() {
    assert(isPalindrome("A man, a plan, a canal: Panama"));
    assert(!isPalindrome("race a car"));
    assert(!isPalindrome("1a2"));
    return 0;
}

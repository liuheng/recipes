#include <cstdio>
#include <cassert>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (int i=0; i<s.length(); ++i) {
        if ('(' == s[i] || '[' == s[i] || '{' == s[i]) {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                return false;
            } else if (st.top() != '(' && ')' == s[i]) {
                return false;
            } else if (st.top() != '[' && ']' == s[i]) {
                return false;
            } else if (st.top() != '{' && '}' == s[i]) {
                return false;
            } else {
                st.pop();
            }
        }
    }
    return true;
}

int main() {
    assert(!isValid("]"));
    return 0;
}

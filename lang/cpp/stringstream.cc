#include <string>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <functional>

using namespace std;

string count_and_say(const string &s) {
    stringstream ss;
    for (string::const_iterator it = s.begin(); it!= s.end();) {
        string::const_iterator it2 = find_if(it, s.end(), bind1st(not_equal_to<char>(), *it));
        ss << distance(it, it2) << *it;
        it = it2;
    }
    return ss.str();
}

int main() {
    string s("1");
    for (int i=1; i<6; ++i)
        s = count_and_say(s);
    printf("%s\n", s.c_str());
    return 0;
}

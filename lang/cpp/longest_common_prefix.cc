#include <cstdio>
#include <vector>
#include <string>

using namespace std;

string commonPrefix(const string &s1, const string &s2) {
    string s;
    int i = 0;
    int length = min(s1.length(), s2.length());
    while (s1[i] == s2[i] && i < length) {
        s.push_back(s1[i]);
        i++;
    }
    return s;
}

string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() <= 1) {
        return "";
    } else {
        string s = commonPrefix(strs[0], strs[1]);
        printf("%s\n", s.c_str());
        for (int i=2; i<strs.size(); ++i) {
            s = commonPrefix(s, strs.at(i));
        }
        return s;
    }
}

int main() {
    vector<string> strs;
    strs.push_back("abcde");
    strs.push_back("abcdx");
    strs.push_back("abcxe");
    strs.push_back("abe");
    printf("%s\n", longestCommonPrefix(strs).c_str());
    return 0;
}

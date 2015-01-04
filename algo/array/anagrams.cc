//Write a method to decide if two strings are anagrams or not.

#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

//sort and compare
bool isAnagram1(const string &s1, const string &s2) {
    if (s1 == s2 || s1.length() != s2.length() || s1 == "" || s2 == "") {
        return false;
    }
    string s1c = s1;
    string s2c = s2;
    sort(&s1c[0], &s1c[0] + s1.length());
    sort(&s2c[0], &s2c[0] + s2.length());
    return s1c == s2c;
}

bool isAnagram2(const string &s1, const string &s2) {
    if (s1 == s2 || s1.length() != s2.length() || s1 == "" || s2 == "") {
        return false;
    }

    int len = s1.length();
    int ticks[128] = {0};
    for (int i=0; i<len; ++i) {
        ++ticks[s1.at(i)];
        --ticks[s2.at(i)];
    }

    for (int i=0; i<128; ++i) {
        if (ticks[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(true == isAnagram1("abccdee", "acedceb"));
    assert(false == isAnagram1("abccdef", "acedceb"));
    assert(false == isAnagram1("aced", "acedceb"));
    assert(false == isAnagram1("abcdefg", "abcdefg"));
    assert(false == isAnagram1("", ""));

    assert(true == isAnagram1("abccdee", "acedceb"));
    assert(false == isAnagram2("abccdef", "acedceb"));
    assert(false == isAnagram2("aced", "acedceb"));
    assert(false == isAnagram2("abcdefg", "abcdefg"));
    assert(false == isAnagram2("", ""));

    return 0;
}

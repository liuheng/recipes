//Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring ( i.e., “waterbottle” is a rotation of “erbottlewat”).

#include <cassert>
#include <string>

using namespace std;

bool isSubstring(const string &s1, const string &s2) {
    return s2.find(s1) != string::npos;
}

bool isRotation(const string &s1, const string &s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    return isSubstring(s1, s2 + s2);
}

int main() {
    string s1 = "defgabc";
    string s2 = "abcdefg";
    string s3 = "fgabcde";
    string s4 = "efgabcd";
    string s5 = "defabcd";
    assert(true == isRotation(s1, s2));
    assert(true == isRotation(s1, s3));
    assert(true == isRotation(s1, s4));
    assert(false == isRotation(s1, s5));
    return 0;
}

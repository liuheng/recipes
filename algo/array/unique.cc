//Implement an algorithm to determine if a string has all unique characters.
//What if you can not use additional data structures?

#include <cassert>
#include <cstddef>

using namespace std;

// 认为s只包含ascii字符
bool isUnique(const char *s) {
    if (s == NULL) {
        return true;
    }
    int a[4] = {0};
    const char *p = s;
    for (; *p != '\0'; ++p) {
        int index = *p / 32;
        int bais = *p % 32;
        if (a[index] & (1 << bais)) {
            return false;
        } else {
            a[index] |= 1 << bais;
        }
    }
    return true;
}

// 认为s只包含小写字母
bool isUnique2(const char *s) {
    if (s == NULL) {
        return true;
    }
    int a = 0;
    const char *p = s;
    for (; *p != '\0'; ++p) {
        int index = (*p - 'a') / 32;
        int bais = (*p - 'a') % 32;
        if (a & (1 << bais)) {
            return false;
        } else {
            a |= 1 << bais;
        }
    }
    return true;
}

int main() {
    assert(true == isUnique(NULL));
    assert(true == isUnique("abcde \t\r\n"));
    assert(false == isUnique("abcde \tb\n"));

    assert(true == isUnique2(NULL));
    assert(true == isUnique2("godfather"));
    assert(false == isUnique2("hello world"));
}

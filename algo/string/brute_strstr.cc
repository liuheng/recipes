#include <cstring>
#include <cassert>

using namespace std;

int brute_match(const char *t, const char *p) {
    size_t tlen = strlen(t);
    size_t plen = strlen(p);

    size_t i = 0;
    size_t j = 0;
    while (i < tlen && j < plen) {
        if (t[i] == p[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == plen) {
        return i - j;
    } else {
        return -1;
    }
}

int main () {
    const char *t = "bbc abcdab abcdabcdabde";
    const char *p1 = "abcdabd";
    const char *p2 = "abcdabe";
    assert(brute_match(t, p1) == 15);
    assert(brute_match(t, p2) == -1);
    return 0;
}

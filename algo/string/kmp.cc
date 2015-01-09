#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

void calc_next(const char *p, int next[]) {
    int plen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < plen - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            if (p[j] != p[k]) {
                next[j] = k; // 优化p[i] = p[next[i]]的情况
            } else {
                next[j] = next[k];
            }
        } else {
            k = next[k];
        }
    }
}

int kmp(const char *t, const char *p) {
    int tlen = strlen(t);
    int plen = strlen(p);
    int next[plen] = {0};
    calc_next(p, next);
    int i = 0;
    int j = 0;

    while (i < tlen && j < plen) { // 因为这里j有可能为-1，所以plen必须为有符号数，不能为size_t
        if (j == -1 || t[i] == p[j]) {
            ++i;
            ++j;
        } else {
            j = next[j]; // 关键移动操作
        }
    }
    if (j == plen) {
        return i - j;
    } else {
        return -1;
    }
}

int main() {
    const char *t = "bbc abcdab abcdabcdabde";
    const char *p1 = "abcdabd";
    const char *p2 = "abcdabe";
    assert(kmp(t, p1) == 15);
    assert(kmp(t, p2) == -1);
    return 0;
}

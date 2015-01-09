#include <cassert>
#include <cstring>
#include <iostream>

#ifndef CHARSET
#define CHARSET (256)
#endif

using namespace std;

void build_bc_table(const char *x, int m, int bct[]) {
    for (int i = 0; i < CHARSET; ++i) {
        bct[i] = m;
        for (i = 0; i < m - 1; ++i) {
            bct[x[i]] = m - i - 1;
        }
    }
}

void calc_suffixes(const char *x, int m, int suffix[]) {
    int q = m -1;
    suffix[m-1] = m;
    for (int i = m-2; i >= 0; --i) {
        q = i;
        while(q>=0 && x[q] == x[m-1-i+q]) {
            --q;
        }
        suffix[i]=i-q;
    }
}

void build_gs_table(const char *x, int m, int gst[]) {
    int i = 0;
    int j = 0;
    int suff[m] = {0};
    calc_suffixes(x, m, suff);
    for (; i < m; ++i) {
        gst[i] = m;
    }
    for (i = m - 1; i >= 0; --i) {
        if (suff[i] == i + 1) {
            for (; j < m - 1 - i; ++j) {
                if (gst[j] == m) {
                    gst[j] = m - 1 - i;
                }
            }
        }
    }
    for (i = 0; i <= m - 2; ++i) {
        gst[m - 1 - suff[i]] = m - 1 - i;
    }
}

int bmsearch(const char *t, const char *p) {
    int tlen = strlen(t);
    int plen = strlen(p);
    int i = tlen - 1;
    int j = 0;

    int bct[plen] = {0};
    build_bc_table(p, plen, bct);
    int gst[plen] = {0};
    build_gs_table(p, plen, gst);

    while (j <= tlen - plen) {
        for (; i >= 0 && p[i] ==t[i + j]; --i) {
            if (i < 0) {
                return 1;
            } else {
                j += max(gst[i], bct[t[i]] - (plen - 1 - i));
            }
        }
    }
    return -1;
}

int main() {
    const char *t = "here is a simple example";
    const char *p1 = "example";
    const char *p2 = "smple";
    assert(bmsearch(t, p1) == 15);
    assert(bmsearch(t, p2) == -1);
    return 0;
}

//Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.

#include <cassert>
#include <cstring>
#include <cstdio>

void zeroMatrix(int *a, int M, int N) {
    bool row[M];
    bool col[N];
    for (int i=0; i<M; ++i) {
        row[i] = false;
    }
    for (int i=0; i<N; ++i) {
        col[i] = false;
    }
    for (int i=0; i<M; ++i) {
        for (int j=0; j<N; ++j) {
            if (*(a+N*i+j) == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i=0; i<M; ++i) {
        for (int j=0; j<N; ++j) {
            if (row[i] || col[j]) {
                *(a+N*i+j) = 0;
            }
        }
    }
}

int main() {
    int a[15] = {0};
    for (int i=0; i<15; ++i) {
        a[i] = i+1;
    }
    a[3] = 0;
    a[4] = 0;
    a[7] = 0;
    zeroMatrix(a, 3, 5);
    int b[15] = {0,0,0,0,0,0,0,0,0,0,11,12,0,0,0};
    assert(memcmp(a, b, 15) == 0);
}

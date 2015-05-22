#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

const int N = 4;
int A[N][N];
int f[N][N];

void print_metrix(int A[][4]) {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<=i; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int solve(int A[][4], int i, int j) {
    if (i == 4) return f[i][j] = A[i][j];
    if (f[i][j] != 0) return f[i][j];
    return f[i][j] = max(solve(A, i+1, j), solve(A, i+1, j+1)) + A[i][j];
}

int main() {
    freopen("data.in", "r", stdin);
    for (int i=0; i<N; ++i) {
        for (int j=0; j<=i; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    print_metrix(A);
    printf("%d\n", solve(A, 0, 0));
    return 0;
}

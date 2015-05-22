#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

const int N = 4;
int A[N][N];
pair<int, int> f[N][N];

void print_metrix(int A[][4]) {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<=i; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    freopen("data.in", "r", stdin);
    for (int i=0; i<N; ++i) {
        for (int j=0; j<=i; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    print_metrix(A);

    for (int i=N-1; i>=0; --i) {
        for (int j=0; j<=i; ++j) {
            if (i == N-1) {
                f[i][j].first = A[i][j];
                f[i][j].second = 0;
            } else {
                if (f[i+1][j] > f[i+1][j+1]) {
                    f[i][j].first = f[i+1][j].first + A[i][j];
                    f[i][j].second = -1;
                } else {
                    f[i][j].first = f[i+1][j+1].first + A[i][j];
                    f[i][j].second = 1;
                }
            }
        }
    }
    printf("%d\n", f[0][0].first);

    int i = 0;
    int j = 0;
    int pv = 0;
    while ((pv = f[i][j].second) != 0) {
        printf("%d ", A[i][j]);
        if (pv == 1)
            j++;
        i++;
    }
    printf("%d\n", A[i][j]);
    return 0;
}

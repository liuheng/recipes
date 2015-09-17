#include <cstdio>

using namespace std;

int dp(int A[], int N, int m)

int subM(int A[], int N, int m) {
    int *table[m+1] = new int[N+1];
    memset(table, INT_MIN, (N+1) * (m+1) * sizeof(int));
    for (int i=0; i<N+1; ++i) table[0][j] = 0;
    for (int i=0; i<m+1; ++i) table[i][0] = 0;
    for (int j=1; j<m+1; ++j) {
        for (int i=1; i<N+1; ++i) {
            table[i][j] = max(table[i-1][j] + A[i], table[i][j]);
            for (int k=i-1; k<j; ++k) {
                table[][]
            }

        }
    }
}

int main() {
    int A[] = {2, 6, -1, 4, -2, 3, -2, 3};
    printf("%d\n", subM(A, 8, 3);
}

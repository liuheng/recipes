#include <cstdio>

void merge(int A[], int m, int B[], int n) {
    if (m == 0 || n == 0) {
        return;
    }
    int X = m + n - 1;
    m--;
    n--;
    while (m >= 0 && n >= 0) {
        if (A[m] >= B[n]) {
            A[X] = A[m];
            --m;
        } else {
            A[X] = A[n];
            --n;
        }
        --X;
    }
    while (n > 0) {
        A[X--] = B[n--];
    }
}

int main() {
    int *A = new int[1];
    int *B = new int[1];
    B[0] = 1;
    merge(A, 0, B, 1);
    printf("%d\n", A[0]);
}

#include <cstdio>
#include <cstring>

using namespace std;

int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

int kt(int n, char a[]) {
    int num = 0;
    for (int i=0; i<n; ++i) {
        int t = 0;
        for (int j=i+1; j<n; ++j) {
            if (a[j] < a[i]) ++t;
        }
        num += t * fac[n - i - 1];
    }
    return num + 1;
}

void rkt(int n, int k, char s[]) {
    --k;
    int i = 0;
    int j = 0;
    int *visit = new int[n+1];
    memset(visit, 0, n * sizeof(int));
    for (i=0; i<n; ++i) {
        int t = k/fac[n - i - 1];
        for (j=1; j<=n; ++j) {
            if (!visit[j]) {
                if (t == 0) break;
                --t;
            }
        }
        s[i] = '0' + j;
        visit[j] = 1;
        k %= fac[n - i - 1];
    }
    delete []visit;
}

int main() {
    int n = 5;
    char a[] = {3, 5, 1, 4, 2};
    int k = kt(5, a);
    printf("%d\n", k);
    rkt(5, k, a);
    for (auto c: a) printf("%c ", c);
    printf("\n");
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int minCut(const string &s) {
    int N = s.length();
    bool p[N][N];
    int f[N+1];
    for (int j=0; j<=N; ++j) {
        f[j] = j-1;
        p[j][j] = true;
        for (int i=0; i<j; ++i) {
            if (s.at(i) == s.at(j-1) && (j - i < 2 || p[i+1][j-1])) {
                p[i][j] = true;
                f[j] = min(f[j], f[i]+1);
            } else {
                p[i][j] = false;
            }
        }
    }
    return f[N];
}

int main() {
    printf("%d\n", minCut("abcbc"));
    return 0;
}

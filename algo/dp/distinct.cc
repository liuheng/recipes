#include <vector>
#include <cstdio>
#include <string>

using namespace std;

int numDistinct(const string &S, const string &T) {
    vector<int> f(T.size() + 1);
    f[0] = 1;
    for (int i = 0; i < S.size(); ++i) {
        for (int j = T.size() - 1; j >= 0; --j) {
            f[j + 1] += S[i] == T[j] ? f[j] : 0;
        }
    }
    return f[T.size()];
}

int main() {
    printf("%d\n", numDistinct("rabbit", "rabbt"));
    return 0;
}

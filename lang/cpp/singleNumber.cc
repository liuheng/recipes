#include <cstdio>
#include <unordered_map>

using namespace std;

int singleNumber(int A[], int n) {
    unordered_map<int, int> M;
    for (int i=0; i<n; ++i) {
        auto it = M.find(A[i]);
        if (it != M.end()) {
            it->second += 1;
        } else {
            M[A[i]] = 1;
        }
    }
    for (auto x: M) {
        if (x.second == 1) {
            return x.first;
        }
    }
    return 0;
}

int main() {
    int A[] = {2, 2, 3, 2};
    printf("%d\n", singleNumber(A, 4));
    return 0;
}

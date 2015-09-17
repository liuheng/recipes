#include <cstdio>
#include <stack>

using namespace std;

int replaceNextLargest(int A[], int N) {
    stack<int> S;
    S.push(0);
    for (int i=1; i<N; ++i) {
        while (!S.empty() && A[i] > A[S.top()]) {
            A[S.top()] = A[i];
            S.pop();
        }
        S.push(i);
    }
}

int main() {
    int A[] = {2, 12, 8, 6, 5, 1, 2, 10, 3, 2};
    replaceNextLargest(A, 10);
    for (int i=0; i<10; ++i) printf("%d ", A[i]);
    printf("\n");
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void PrintVec(const vector<int> &v) {
    for (const int &i : v) {
        printf("%i\t", i);
    }
    printf("\n");
}

bool pred(const int &a) {
    return a / 5 == 1;
}

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v2;
    typedef vector<int>::iterator VIT;
    v2.resize(10);
    copy_backward(begin(v1), end(v1), end(v2));
    VIT it = find_if(begin(v1), end(v2), pred);
    printf("%d\n", *it);
    // PrintVec(v2);
    return 0;
}

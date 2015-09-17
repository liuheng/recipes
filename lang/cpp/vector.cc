#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    vector<int> V = {1, 2, 3, 4, 5, 3, 4, 3};
    printf("%d\n", V.size());
    V.erase(remove(V.begin(), V.end(), 3), V.end());
    printf("%d\n", V.size());
    return 0;
}

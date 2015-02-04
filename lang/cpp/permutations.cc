#include <cstdio>
#include <vector>

using namespace std;



vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;
    
}

int main() {
    vector<int> v = {1, 2, 3, 3};
    auto result = permute(v);
    for (auto i: result) {
        for (int k: i) {
            printf("%d ", k);
        }
        printf("\n");
    }
}

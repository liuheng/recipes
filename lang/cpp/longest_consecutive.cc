#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int longestConsecutive(vector<int> &num) {
    set<int> s;
    set<int> sd;
    int M = 1;
    for (int i: num) {
        s.insert(i);
    }
    for (int i: s) {
        int k = 1;
        sd.insert(i);
        for (int j=i-1; s.find(j)!=s.end() && sd.find(j)==sd.end();--j) {
            k++;
            sd.insert(j);
        }
        for (int j=i+1; s.find(j)!=s.end() && sd.find(j)==sd.end();++j) {
            k++;
            sd.insert(j);
        }
        M = max(M, k);
    }
    return M;
}

int main() {
    vector<int> v = {0, -1};
    printf("%d\n", longestConsecutive(v));
    return 0;
}

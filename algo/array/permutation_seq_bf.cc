#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool permute(int n, int &k, vector<int> &path) {
        if (path.size() == n) {
            for (int i: path)
                printf("%d ", i);
            printf("\n");
            if (--k == 0) return true;
        }
        for (int i=1; i<=n; ++i) {
            if (find(path.begin(), path.end(), i) == path.end()) {
                path.push_back(i);
                if (permute(n, k, path))
                    return true;
                path.pop_back();
            }
        }
        return false;
    }
    string getPermutation(int n, int k) {
        vector<int> path;
        permute(n, k, path);
        string s;
        for (int i: path)
            s += '0' + i;
        return s;
    }
};

int main() {
    Solution S;
    string s = S.getPermutation(3, 5);
    printf("%s", s.c_str());
    return 0;
}

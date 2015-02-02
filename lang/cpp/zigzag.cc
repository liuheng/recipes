#include <cstdio>
#include <string>

using namespace std;

string convert(string s, int nRows) {
    const int M = nRows * 2 - 2;
    if (M == 0) {
        return s;
    }
    string sx;
    for (int i=0; i<=nRows-1; ++i) {
        for (int j=0; j<s.length(); ++j) {
            if (j % M == i || j % M == M-i) {
                sx += s[j];
            }
        }
    }
    return sx;
}

int main() {
    printf("%s\n", convert("A", 1).c_str());
}

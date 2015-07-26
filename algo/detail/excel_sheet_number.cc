#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int titleToNumber(string s) {
    int sum = 0;
    int len = s.length();
    for (int i=0; i<len; ++i) {
        sum += (s[i] - 'A' + 1) * pow(26, len - i - 1);
    }
    return sum;
}

int main() {
    printf("%d\n", titleToNumber("BC"));
    return 0;
}

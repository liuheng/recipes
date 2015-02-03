#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int romanToInt(string s) {
    int length = s.length();
    int sum = 0;
    for (int i=0; i<length; ++i) {
        sum += (s[i] - '0') * pow(10, (length-i-1));
    }
    return sum;
}

int main() {
    printf("%d\n", romanToInt("12345"));
    return 0;
}

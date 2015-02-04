#include <cstdio>
#include <string>

using namespace std;

string convertToTitle(int n) {
    if (n == 0) {
        return "";
    }
    string s;
    int a = 0;
    int b = 0;
    do {
        a = n / 26;
        b = n % 26;
        if (b == 0) {
            s.insert(begin(s), 'Z');
            a--;
        } else {
            s.insert(begin(s), b + 'A' - 1);
        }
        n = a;
    } while (a > 26);
    if (a != 0) {
        s.insert(begin(s), a + 'A' - 1);
    }
    return s;
}

int main() {
    printf("%s\n", convertToTitle(0).c_str());
    printf("%s\n", convertToTitle(1).c_str());
    printf("%s\n", convertToTitle(2).c_str());
    printf("%s\n", convertToTitle(26).c_str());
    printf("%s\n", convertToTitle(27).c_str());
    printf("%s\n", convertToTitle(51).c_str());
    printf("%s\n", convertToTitle(52).c_str());
    printf("%s\n", convertToTitle(53).c_str());
    return 0;
}

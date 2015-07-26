#include <cstdio>
#include <cassert>
#include <cmath>

using namespace std;

int getPos(int x, int p) {
    int k = x/int(pow(10, p-1)) % 10;
    printf("%d - %d - %d\n", k, x, p);
    return k;
}

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    } else if (x >= 0 && x < 10) {
        return true;
    } else {
        int length = 0;
        int k = x;
        while (k != 0) {
            k /= 10;
            length++;
        }
        printf("length: %d\n", length);
        for (int i=1; i<=length/2; ++i) {
            if (getPos(x, i) != getPos(x, length-i+1)) {
                return false;
            }
            printf("\n");
        }
        return true;
    }
}

int main() {
    assert(isPalindrome(1410110141));
    printf("%d\n", 1410110141/10000000000);
}

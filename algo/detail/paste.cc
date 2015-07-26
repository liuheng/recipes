#include <cstdio>

using namespace std;

int main() {
    int value = 0;
    int index = 0;
    while (true) {
        int n = 0;
        int base = 1;
        scanf("%d", &value);
        if (value < 0) {
            break;
        }
        ++index;
        while (true) {
            if (base >= value) {
                break;
            }
            base = base << 1;
            ++n;
        }
        printf("Case %d: %d\n", index, n);
    }
    return 0;
}

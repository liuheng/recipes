#include <cstdio>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    int carry = 0;
    auto it = prev(end(digits));
    carry = (*it + 1) / 10;
    *it = (*it + 1) % 10;
    while(carry) {
        if (it > begin(digits)) {
            it = prev(it);
        } else {
            break;
        }
        carry = (*it + 1) / 10;
        *it = (*it + 1) % 10;
    }
    if (carry) {
        digits.insert(it, 1);
    }
    return digits;
}

int main() {
    vector<int> a = {9, 9, 9};
    auto b = plusOne(a);
    for (int i: a) {
        printf("%d\n", i);
    }
    return 0;
}

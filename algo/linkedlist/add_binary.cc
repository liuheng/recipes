#include <cstdio>
#include <string>

using namespace std;

string addBinary(string a, string b) {
    auto ia = prev(end(a));
    auto ib = prev(end(b));
    int sum = (*ia - '0') + (*ib - '0');
    int carry = sum == 2;
    char c = sum % 2 + '0';
    string s;
    s.insert(begin(s), c);
    while (ia != begin(a) && ib != begin(b)) {
        ia = prev(ia);
        ib = prev(ib);
        sum = (*ia - '0') + (*ib - '0') + carry;
        carry = sum >= 2;
        c = sum % 2 + '0';
        s.insert(begin(s), c);
    }
    if (!(ia == begin(a) && ib == begin(b))) {
        string sc = ia == begin(a) ? b : a;
        auto ic = next(begin(sc), ia == begin(a) ? ib-begin(b) : ia-begin(a));
        while (ic != begin(sc)) {
            ic = prev(ic);
            sum = (*ic - '0') + carry;
            carry = sum == 2;
            c = sum % 2 + '0';
            s.insert(begin(s), c);
        }
    }
    if (carry) {
        s.insert(begin(s), '1');
    }
    return s;
}

int main() {
    string s = addBinary("1010", "1011");
    printf("%s\n", s.c_str());
    return 0;
}

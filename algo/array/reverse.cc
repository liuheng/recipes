#include <cassert>
#include <cstddef>
#include <cstring>

using namespace std;

void swap(char &a, char &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void reverse(char *s) {
    if (s == NULL) {
        return;
    }
    char *p1 = s;
    char *p2 = s;
    for (; *p1 != '\0'; ++p1) {
        ;
    }
    --p1;
    while (p1 > p2) {
        swap(*p1--, *p2++);
    }
}

int main() {
    char s1[] = "abcdefg";
    char s2[] = "hello world";
    reverse(s1);
    reverse(s2);
    assert(strcmp("gfedcba", s1) == 0);
    assert(strcmp("dlrow olleh", s2) == 0);
    return 0;
}

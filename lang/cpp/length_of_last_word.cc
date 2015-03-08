#include <cctype>
#include <cstdio>
#include <cstring>
#include <cassert>

int lengthOfLastWord(const char *s) {
    int size = strlen(s);
    const char *p = s + size - 1;
    while (::isspace(*p) && p >= s) --p;
    const char *end = p;
    while (::isalnum(*p) && p >= s) --p;
    return end - p;
}

int main() {
    printf("%d\n", lengthOfLastWord("a"));
}

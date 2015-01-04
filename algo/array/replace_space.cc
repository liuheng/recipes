//Write a method to replace all spaces in a string with ‘%20’.

#include <cassert>
#include <cstring>

using namespace std;

// 认为字符串后面长度够
void replaceSpace(char *s) {
    if (s == NULL) {
        return;
    }
    char *p = s;
    int length = 0;
    for (; *p != '\0'; ++p) {
        if (*p == ' ') {
            length += 3;
        } else {
            ++length;
        }
    }
    *(s + length) = '\0';
    char *q = s + length - 1;
    --p;
    for (; p >= s; --p) {
        if (*p == ' ') {
            *q-- = '0';
            *q-- = '2';
            *q-- = '%';
        } else {
            *q-- = *p;
        }
    }
    return;
}

int main() {
    char s1[64] = {0};
    strcpy(s1, "I am a good man.");
    replaceSpace(s1);
    assert(strcmp("I%20am%20a%20good%20man.", s1) == 0);

    char s2[64] = {0};
    strcpy(s2, "   ");
    replaceSpace(s2);
    assert(strcmp("%20%20%20", s2) == 0);

    return 0;
}

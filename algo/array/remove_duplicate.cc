//Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer.
//NOTE: One or two additional variables are fine. An extra copy of the array is not.

//FOLLOW UP

//Write the test cases for this method.

#include <cassert>
#include <cstddef>
#include <cstring>

//认为只包含ascii字符
char *removeDuplicate(char *s) {
    if (s == NULL) {
        return NULL;
    }
    int a[4] = {0};
    char *base = s;
    char *p = s;
    int index = 0;
    int bais = 0;
    for (; *p != '\0'; ++p) {
        index = *p / 32;
        bais = *p % 32;
        if (!(a[index] & (1 << bais))) {
            *base++ = *p;
            a[index] |= (1 << bais);
        }
    }
    *base = '\0';
    return s;
}

int main() {
    char s1[] = "";
    char s2[] = "aaaaa";
    char s3[] = "aabccccccdddee";
    char s4[] = "hello world";

    assert(strcmp("", removeDuplicate(s1)) == 0);
    assert(strcmp("a", removeDuplicate(s2)) == 0);
    assert(strcmp("abcde", removeDuplicate(s3)) == 0);
    assert(strcmp("helo wrd", removeDuplicate(s4)) == 0);
    assert(NULL == removeDuplicate(NULL));
    return 0;
}

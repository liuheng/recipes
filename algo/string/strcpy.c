#include <stdio.h>
#include <assert.h>

char *strcpy(char *to, const char * from) { // from为const char *，返回char *
    assert(to != NULL && from != NULL); // 参数检查
    char *ret = to;
    // 考虑内存重叠
    if (to < from) {// 从前往后复制
        while ((*to++ = *from++) != '\0') {
            ;
        }
        *to = '\0'; // 补末尾的'\0'
    }
    else if (to > from) {// 从后往前复制
        // 考虑内存重叠，因此需要计算from的长度
        const char *p = from;
        for (; *p != '\0'; ++p) {
            ;
        }
        size_t length = (p - from);

        from = from + length -1;
        to = to + length;
        *to-- = '\0'; // 补末尾的'\0'
        while (length-- > 0) {
            *to-- = *from--;
        }
    }
    else { // 最不可能出现的情况放到最后
        ;
    }
    return ret; // 返回ret，支持链式copy
}

int main() {
    // 测试用例考虑各种情况
    char *from = "hello world";
    char to[32] = {0};
    strcpy (to, from);
    printf("to is %s\n", to);

    char buf1[] = "        abcdefg\0       ";
    char buf2[] = "        abcdefg\0       ";
    char buf3[] = "        abcdefg\0       ";
    char buf4[] = "        abcdefg\0       ";
    char buf5[] = "        abcdefg\0       ";
    strcpy(buf1+4, buf1+8);
    printf("to is %s\n", buf1+4);

    strcpy(buf2+12, buf2+8);
    printf("to is %s\n", buf2+12);

    strcpy(buf2+8, buf2+8);
    printf("to is %s\n", buf3+8);

    strcpy(buf4+6, strcpy(buf4+4, buf4+8));
    printf("to is %s\n", buf4+6);

    strcpy(buf5+10, strcpy(buf5+12, buf5+8));
    printf("to is %s\n", buf5+10);
    return 0;
}

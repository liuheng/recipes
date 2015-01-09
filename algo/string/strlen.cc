#include <stdio.h>
#include <sys/types.h>

size_t strlen(const char *s) { // 使用const char *， 返回size_t
    if (s == NULL) { // 检查参数是否为NULL
        return 0;
    }
    const char *p = s; // 这样做可以只赋值一次，又不想不初始化
    for (; *p != '\0'; ++p) {// 所有的比较语句都准确表达，回避隐式类型转换/提升
        ; // 什么都不做，也加{}，并显式写出 ;
    }
    return (p - s); // 没有临时变量
}

size_t strlen1(const char *s) {
    if (s == NULL) {
        return 0;
    }
    const char *p = s;
    size_t len = 0; // 有临时变量
    while (*p++ != '\0') {
        ++len;
    }
    return len;
}


int main() {
    // 测试用例考虑各种情况
    char *s0 = NULL;
    const char *s1 = "hello world";

    printf("size of %s is %lu\n", "hello world", strlen("hello world"));
    printf("size of %s is %lu\n", s0, strlen(s0));
    printf("size of %s is %lu\n", s1, strlen(s1));

    printf("size of %s is %lu\n", "hello world", strlen1("hello world"));
    printf("size of %s is %lu\n", s0, strlen1(s0));
    printf("size of %s is %lu\n", s1, strlen1(s1));

    return 0;
}

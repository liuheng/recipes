#include <cstdio>

int fac[] = {1,1,2,6,24,120,720,5040,40320}; //i的阶乘为fac[i]

//康托展开的逆运算,{1...n}的全排列，中的第k个数为s[]
void reverse_kangtuo(int n, int k, char s[]) {
    int i, j, t, vst[8] = {0};
    --k;
    for (i=0; i<n; i++) {
        t = k / fac[n-i-1];
        for (j=1; j<=n; j++)
            if (!vst[j]) {
                if (t == 0)
                    break;
                --t;
            }
            s[i] = '0' + j;
            vst[j] = 1;
            k %= fac[n-i-1];
    }
}

int main() {
    char s[5] = {0};
    reverse_kangtuo(5, 20, s);
    for (int i=0; i<5; ++i) {
        printf("%c ", s[i]);
    }
    printf("\n");
    return 0;
}

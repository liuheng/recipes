#include <cstdio>

int fac[] = {1,1,2,6,24,120,720,5040,40320}; //i的阶乘为fac[i]

// 康托展开-> 表示数字a是 a的全排列中从小到大排，排第几
// n表示1~n个数 a数组表示数字。
int kangtuo(int n,char a[]) {
    int i,j,t,sum;
    sum = 0;
    for(i=0; i<n; ++i) {
        t = 0;
        for(j=i+1; j<n; ++j)
            if(a[i] > a[j])
                ++t;
        sum += t * fac[n-i-1];
    }
    return sum + 1;
}

int main() {
    char a[] = {2, 1, 3, 4};
    printf("%d\n", kangtuo(4, a));
    return 0;
}

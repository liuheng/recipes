#include <cstdio>
#include <climits>

int reverse(int x) {
    bool isPositive = true;
    if(x < 0)
        isPositive = false;
    long long res = 0;//为了防止溢出，用long long
    while(x)
    {
        res = res*10 + x%10;
        x /= 10;
    }
    if(res > INT_MAX || res < INT_MIN) {
        return 0; //isPositive ? INT_MAX : INT_MIN;
    }
    if(!isPositive)
        return res*-1;
    else 
        return res;
}

int main() {
    reverse(-2147483648);
    return 0;
}

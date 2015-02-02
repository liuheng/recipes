#include <forward_list>
#include <cstdio>

void Print(const std::forward_list<int> & a) {
    for (const int &i : a) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    std::forward_list<int> a = {1, 2 ,3 ,4 , 5};
    Print(a);
    a.reverse();
    Print(a);
    return 0;
}

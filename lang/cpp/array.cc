#include <cstdio>
#include <array>

void PrintArray(const std::array<int, 3> &a) {
    for (const int &i : a) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    std::array<int, 3> a1 = {1, 2, 3};
    std::array<int, 3> a2 = {11, 12, 13};
    PrintArray(a1);
    PrintArray(a2);
    printf("---------------\n");

    a1.swap(a2);
    PrintArray(a1);
    PrintArray(a2);
    return 0;
}

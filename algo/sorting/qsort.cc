#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void qsort(int A[], int start, int end) {
    if (start+1 >= end) return;
    int i = start, j = end-1, p = A[start];
    while (i < j) {
        while (i < j && A[j] >= p) j--;
        if (i < j) A[i++] = A[j];
        while (i < j && A[i] < p) i++;
        if (i < j) A[j--] = A[i];
    }
    A[i] = p;
    qsort(A, start, i);
    qsort(A, i+1, end);
}

int main() {
    srand(time(NULL));
    int arr[20] = {0};
    for (int i=0; i<20; ++i) {
        arr[i] = rand() % 100;
    }
    for (int i=0; i<20; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    qsort(arr, 0, 20);
    for (int i=0; i<20; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

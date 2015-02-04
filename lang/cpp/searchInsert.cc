#include <cstdio>

int search(int A[], int begin, int end, int target) {
    if (begin == end) {
        return begin;
    }
    int mid = begin + (end - begin)/2;
    if (target == A[mid]) {
        return mid;
    } else if (target < A[mid]) {
        return search(A, begin, mid, target);
    } else {
        return search(A, mid+1, end, target);
    }
}

int searchInsert(int A[], int n, int target) {
    return search(A, 0, n, target);
}

int main() {
    int A[] = {1,3};
    printf("%d\n", searchInsert(A, 2, 4));
    return 0;
}

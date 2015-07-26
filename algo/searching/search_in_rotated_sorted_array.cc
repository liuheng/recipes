#include <cstdio>

using namespace std;

int search(int A[], int n, int target) {
    int first = 0;
    int last = n;
    while (first < last) {
        int mid = first + (last - first) / 2;
        printf("%d - %d - %d - %d\n", first, last, mid, A[mid]);
        if (target == A[mid]) {
            printf("get %d\n", mid);
            return mid;
        } else if (A[first] <= A[mid]) {
            if (target >= A[first] && target < A[mid]) {
                last = mid;
            } else {
                first = mid + 1;
            }
        } else if (A[last - 1] >= A[mid]) {
            if (target <= A[last - 1] && target > A[mid]) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
    }
    return -1;
}

int main() {
    int arr[] = {3,1};
    int n = 2;
    search(arr, n, 0);
    return 0;
}

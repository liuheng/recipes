#include <cstdio>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void printVec(vector<int> a) {
    for (int i: a) {
        printf("%d ", i);
    }
    printf("\n");
}

int select(vector<int> &num, int start, int end, int k) {
    printf("<1> %d - %d - %d\n", start, end, k);
    printVec(num);
    if (start + 1 >= end) {
        return num[start];
    } else {
        int provt = num[end-1];
        int i = start;
        int j = start;
        for (; j<end-2; ++j) {
            if (num[j] < provt) {
                if (num[i] >= provt) {
                    swap(num[i], num[j]);
                    ++i;
                } else if (i == j) {
                    ++i;
                }
            }
            ++j;
        }
        swap(num[i], num[end-1]);
        printf("<2> %d - %d - %d\n", i, j, k);
        printVec(num);
        if (i < k) {
            return select(num, i+1, end, k-i);
        } else if (i > k) {
            return select(num, start, i, k);
        } else {
            return num[k];
        }
    }
}

int majorityElement(vector<int> &num) {
    return select(num, 0, num.size(), num.size()/2);
}

int main() {
    vector<int> a = {1, 5, 2, 0, 0, -1, -3, 0, 0, 0, 0, 0, 0};
    printf("%d\n", majorityElement(a));
    return 0;
}

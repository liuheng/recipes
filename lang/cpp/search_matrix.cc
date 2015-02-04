#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

bool binarySearch(vector<vector<int> > &matrix, int begin, int end, int target) {
    int M = matrix.size();
    int N = matrix[0].size();
    if (begin == end) {
        return false;
    } else {
        int mid = begin + (end - begin) / 2;
        int row = mid / N;
        int col = mid - row * N;
        printf("%d - %d - %d\n", mid, row, col);
        if (target == matrix[row][col]) {
            return true;
        } else if (target > matrix[row][col]) {
            return binarySearch(matrix, mid+1, end, target);
        } else {
            return binarySearch(matrix, begin, mid, target);
        }
    }
}

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int M = matrix.size();
    if (M == 0) {
        return false;
    }
    int N = matrix[0].size();
    return binarySearch(matrix, 0, M * N, target);
}

int main() {
    vector<int> v1 = {1, 1};
    vector<vector<int> > v;
    v.push_back(v1);
    assert(!searchMatrix(v, 0));
    return 0;
}

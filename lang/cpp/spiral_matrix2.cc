#include <cstdio>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> result;
    int M = matrix.size();
    if (M == 0) return result;
    int N = matrix[0].size();
    int h = 0;
    int g = 0;
    while (h<M/2 && g<N/2) {
        for (int j=g; j<N-g; ++j) {
            result.push_back(matrix[h][j]);
        }
        for (int i=h+1; i<M-h; ++i) {
            result.push_back(matrix[i][N-g-1]);
        }
        for (int j=N-g-1; j>g; --j) {
            result.push_back(matrix[M-h-1][j-1]);
        }
        for (int i=M-h-1; i>h+1; --i) {
            result.push_back(matrix[i-1][g]);
        }
        ++h;
        ++g;
    }
    if (M % 2 != 0 && N >= M) {
        for (int j=g; j<N-g; ++j)
            result.push_back(matrix[h][j]);
    } else if (N % 2 != 0 && M > N) {
        for (int i=h; i<M-h; ++i)
            result.push_back(matrix[i][N-g-1]);
    }
    return result;
}

int main() {
    vector<vector<int> > v;
    vector<int> v1 = {1};
    vector<int> v2 = {4};
    vector<int> v3 = {7};
    //vector<int> v4 = {10, 11, 12};
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    //v.push_back(v4);
    auto result = spiralOrder(v);
    for (int i: result) {
        printf("%d ", i);
    }
    printf("\n");
}

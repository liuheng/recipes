#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    freopen("data.in", "r", stdin);
    int M = 0;
    int N = 0;
    scanf("%d %d\n", &M, &N);
    int **C = new int*[M];
    int *top = new int[M];
    int *bottom = new int[M+1];
    int *left = new int[N];
    int *right = new int[N+1];
    int total = 0;
    for (int i=0; i<M; ++i) {
        C[i] = new int[N];
        for (int j=0; j<N; ++j) {
            scanf("%d ", &C[i][j]);
            total += C[i][j];
        }
    }
    top[0] = 0;
    bottom[0] = total;
    bottom[N] = 0;
    for (int i=1; i<M; ++i) {
        int row = 0;
        for (int j=0; j<N; ++j) {
            row += C[i-1][j];
        }
        top[i] = top[i-1] + row;
        bottom[i] = total - top[i];
    }
    left[0] = 0;
    right[0] = total;
    right[N] = 0;
    for (int j=1; j<N; ++j) {
        int column = 0;
        for (int i=0; i<M; ++i) {
            column += C[i][j-1];
        }
        left[j] = left[j-1] + column;
        right[j] = total - left[j];
    }
    
    int cost = 0;
    int minx = 0;
    int miny = 0;
    for (int i=0; i<M; ++i)
        for (int j=0; j<N; ++j)
            cost += (i + j) * C[i][j];
    int min_cost = cost;
    int line_cost = cost;
    //printf("%d\n", min_cost);
    for (int i=0; i<M; ++i) {
        if (i != 0)
            line_cost = line_cost + top[i] - bottom[i];
        cost = line_cost;
        if (cost < min_cost) {
            min_cost = cost;
            minx = i;
            miny = 0;
        }
        //printf("line cost: %d\n", cost);
        for (int j=0; j<N; ++j) {
            if (j != 0) {
                cost = cost + left[j] - right[j];
                //printf("%d ", cost);
                if (cost < min_cost) {
                    min_cost = cost;
                    minx = i;
                    miny = j;
                }
            }
        }
        //printf("\n");
    }

    printf("%d %d\n", minx, miny);

    for (int i=0; i<M; ++i) delete []C[i];
    delete []top;
    delete []bottom;
    delete []left;
    delete []right;
    return 0;
}

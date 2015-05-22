#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

bool dfs(int coins[], int N, int S, int start, int sum, vector<int> &path, vector<vector<int> > &result) {
    if (sum > S) return false;
    if (S == sum) {
        result.push_back(path);
        return true;
    }
    for (int i=start; i<N; ++i) {
        path.push_back(coins[i]);
        if (dfs(coins, N, S, start, sum+coins[i], path, result))
            return true;
        path.pop_back();
    }
    return false;
}

int main() {
    freopen("data.in", "r", stdin);
    int N;
    int S;
    scanf("%d %d\n", &N, &S);
    printf("%d %d\n", N, S);

    int *coins = new int[N];
    for (int i=0; i<N; ++i)
        scanf("%d\n", &coins[i]);
    sort(coins, coins+N, comp);
    for (int i=0; i<N; ++i)
        printf("%d ", coins[i]);
    printf("\n");

    vector<int> path;
    vector<vector<int> > result;
    dfs(coins, N, S, 0, 0, path, result);
    for (auto v: result) {
        for (int i: v)
            printf("%d ", i);
        printf("\n");
    }

    delete []coins;
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    int height;
    int width;
    int index;
} rect_t;

void print_graph(const vector<vector<int> > &G) {
    for (auto v: G) {
        for (auto i: v) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

int rectIn(const rect_t &r1, const rect_t &r2) {
    if ((r1.height == r2.height && r1.width == r2.width) || (r1.height == r2.width && r1.width == r2.height))
        return 2;
    else if ((r1.height <= r2.height && r1.width <= r2.width) || (r1.height <= r2.width && r1.width <= r2.height))
        return -1;
    else if ((r1.height >= r2.height && r1.width >= r2.width) || (r1.height >= r2.width && r1.width >= r2.height))
        return 1;
    else
        return 0;
}

int solve(const vector<vector<int> > &G, int *d, int i) {
    if (d[i] != -1) return d[i];
    bool end = true;
    for (int j=0; j<G.size(); ++j) {
        if (G[i][j] == 1) {
            d[i] = max(d[i], solve(G, d, j));
            end = false;
        }
    }
    if (end) return d[i] = 1;
    return d[i] = d[i] + 1;
}

void print_path(const vector<vector<int> > &G, int *d, int i) {
    printf("%d ", i);
    for (int j=0; j<G.size(); ++j) {
        if (G[i][j] == 1 && d[i] == d[j] + 1) {
            print_path(G, d, j);
            break;
        }
    }
}

void print_all_path(const vector<vector<int> > &G, int *d, vector<int> &path, vector<vector<int> > &result, int i, int begin) {
    if (begin) path.push_back(i);
    bool end = true;
    for (int j=0; j<G.size(); ++j) {
        if (G[i][j] == 1 && d[i] == d[j] + 1) {
            path.push_back(j);
            print_all_path(G, d, path, result, j, false);
            path.pop_back();
            end = false;
        }
    }
    if (end)
        result.push_back(path);
}

int main() {
    freopen("data.in", "r", stdin);
    int N = 0;
    scanf("%d", &N);
    rect_t *rects = new rect_t[N];
    int *d = new int[N];
    vector<vector<int> > G;
    for (int i=0; i<N; ++i) {
        scanf("%d %d", &rects[i].height, &rects[i].width);
        rects[i].index = i;
        vector<int> v(N, 0);
        G.push_back(v);
        d[i] = -1;
    }

    for (int i=0; i<N; ++i) {
        for(int j=i+1; j<N; ++j) {
            int answer = rectIn(rects[i], rects[j]);
            if (answer == 2) {
                G[i][j] = 1;
                G[j][i] = 1;
            } else if (answer == -1) {
                G[i][j] = 1;
                G[j][i] = 0;
            } else if (answer == 1) {
                G[i][j] = 0;
                G[j][i] = 1;
            } else {
                G[i][j] = 0;
                G[j][i] = 0;
            }
        }
    }
    print_graph(G);

    for (int i=0; i<N; ++i)
        solve(G, d, i);
    int result = 0;
    int start = -1;
    for (int i=0; i<N; ++i) {
        if (result < d[i]) {
            result = d[i];
            start = i;
        }
    }
    printf("start from %d, and result is %d\n", start, result);
    print_path(G, d, 0);
    printf("\n");

    printf("distance array: ");
    for (int i=0; i<N; ++i) printf("%d ", d[i]);
    printf("\n");

    vector<int> starts;
    for (int i=0; i<N; ++i) {
        if (result <= d[i]) {
            result = d[i];
            if (result < d[i])
                starts.empty();
            starts.push_back(i);
        }
    }
    printf("starts: ");
    for (int i: starts) printf("%d ", i);
    printf("\n");
    for (int i: starts) {
        vector<int> path;
        vector<vector<int> > result;
        print_all_path(G, d, path, result, i, true);
        for (auto v: result) {
            for (auto i: v) printf("%d ", i);
            printf("\n");
        }
    }
    return 0;
}

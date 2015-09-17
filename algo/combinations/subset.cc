#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

void subset(vector<int> &V, int start, vector<int> &path, vector<vector<int> > &result) {
    if (start == V.size()) {
        result.push_back(path);
        return;
    }
    subset(V, start+1, path, result);
    path.push_back(V.at(start));
    subset(V, start+1, path, result);
    path.pop_back();
}

void subset2(vector<int> &V, int start, vector<int> &path, vector<vector<int> > &result) {
    result.push_back(path);
    for (int i=start; i<V.size(); ++i) {
        if (i != start && V.at(i) == V.at(i-1)) continue;
        path.push_back(V.at(i));
        subset2(V, i+1, path, result);
        path.pop_back();
    }
}

void printV(vector<vector<int> > &V) {
    for (auto v: V) {
        for (int i: v) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

bool comp(vector<int> &a, vector<int> &b) {
    bool match = true;
    if (a.size() != b.size()) return false;
    for (int i=0; i<a.size(); ++i) {
        if (a.at(i) != b.at(i)) match = false;
    }
    return match;
}

int main() {
    vector<int> path;
    vector<vector<int> > result;
    vector<int> V = {1, 2, 3, 4, 5};
    subset(V, 0, path, result);
    sort(result.begin(), result.end());
    result.resize(distance(result.begin(), unique(result.begin(), result.end(), comp)));
    printV(result);
    printf("-----------------------\n");
    path.clear();
    result.clear();
    subset2(V, 0, path, result);
    printV(result);
    return 0;
}

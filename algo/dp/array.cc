#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct {
    int low;
    int high;
    int weight;
} Interval;

inline bool comp(const Interval &r1, const Interval &r2) {
    return r1.high < r2.high;
}

int main() {
    freopen("data.in", "r", stdin);

    int N;
    int *table = new int[N];
    memset(table, 0, sizeof(int) * N);
    scanf("%d\n", &N);
    Interval *intervals = new Interval[N];
    for (int i=0; i<N; ++i)
        scanf("%d %d %d\n", &intervals[i].low, &intervals[i].high, &intervals[i].weight);
    sort(intervals, intervals+N, comp);
    for (int i=0; i<N; ++i)
        printf("%d %d %d\n", intervals[i].low, intervals[i].high, intervals[i].weight);
    printf("\n");

    for(int i=0; i<N; ++i) {
        for (int j=0; j<i; ++j) {
            if (intervals[j].high <= intervals[i].low)
                table[i] = max(table[i], table[j]);
        }
        table[i] += intervals[i].weight;
    }
    int max_weight = 0;
    for (int i=0; i<N; ++i)
        if (max_weight < table[i])
            max_weight = table[i];

    printf("%d\n", max_weight);

    for (int i=0; i<N; ++i)
        printf("%d ", table[i]);
    printf("\n");

    int current_max_index = N;
    while (max_weight > 0) {
        int index = 0;
        int value = 0;
        for (int i=0; i<current_max_index; ++i) {
            if (value < table[i]) {
                value = intervals[i].weight;
                index = i;
            }
        }
        for (int j=index; j>0; --j) {
            if (intervals[j].high > intervals[index].low)
                current_max_index--;
        }
        max_weight -= value;
        printf("select %d\n", index);
    }

    delete []table;
    delete []intervals;
    return 0;
}

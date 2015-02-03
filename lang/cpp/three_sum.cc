#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> & num) {
    vector<vector<int> > v;
    if (num.size() < 3) {
        return v;
    }
    sort(begin(num), end(num));
    auto first = begin(num);
    auto last = end(num) - 1;
    auto it1 = begin(num);
    for (; it1<last-1; ++it1) {
        auto it3 = last;
        auto it2 = it1 + 1;
        if (it1 > first && *it1 == *(it1-1)) {
            continue;
        }
        while (it2 < it3) {
            if (*it1 + *it2 + *it3 < 0) {
                do {
                    ++it2;
                } while (*it2 == *(it2-1) && it2 < it3-1);
            } else if (*it1 + *it2 + *it3 > 0) {
                do {
                    --it3;
                } while (*it3 == *(it3+1) && it3 > it2+1);
            } else {
                vector<int> ret;
                v.push_back({*it1, *it2, *it3});
                do {
                    ++it2;
                } while (*it2 == *(it2-1) && it2 < it3-1);
                do {
                    --it3;
                } while (*it3 == *(it3+1) && it3 > it2+1);
            }
        }
    }
    return v;
}

int main () {
    vector<int> S = {0, 0, 0, 0};
    auto v = threeSum(S);
    for (auto I: v) {
        for (auto i: I) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}

#include <cstdio>
#include <vector>

using namespace std;

void find_min(vector<int> &num, int begin, int end, int &current) {
    if (begin>=end) {
        return;
    }
    int mid = begin + (end-begin)/2;
    if (num.at(mid) < current) {
        current = num.at(mid);
    }
    if (mid-1 >= 0 && num.at(mid-1) < current) {
        find_min(num, begin, mid, current);
    }
    if (end-1 > 0 && num.at(end-1) < current) {
        find_min(num, mid+1, end, current);
    }
}

int findMin(vector<int> &num) {
    if (num.size() == 0) {
        return 0;
    }
    int current = num.at(0);
    find_min(num, 0, num.size(), current);
    return current;
}

int main() {
    vector<int> v = {2,1};
    printf("%d\n", findMin(v));
}

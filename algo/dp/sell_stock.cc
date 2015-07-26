#include <cstdio>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
    int _max = *begin(prices);
    int _min = _max;
    int _profit = 0;
    int _old = *begin(prices);
    bool _trend = false;
    for (vector<int>::iterator it = begin(prices); it != prices.end(); ++it) {
        if (*it >= _old) {
            if (!_trend) {
                _trend = true;
                _min = _old;
            }
            _max = *it;
        } else {
            if (_trend) {
                _trend = false;
                _profit += _max - _min;
                printf("%d - %d\n", _max, _min);
            }
            _min = *it;
        }
        _old = *it;
    }
    if (_trend) {
        _profit += _max - _min;
        printf("%d - %d\n", _max, _min);
    }
    return _profit;
}

int main() {
    vector<int> a = {5, 7, 6, 4, 3, 4, 6, 5, 7, 9};
    printf("%d\n", maxProfit(a));
    return 0;
}

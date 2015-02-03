#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> h;
    for (int i=0; i<numbers.size(); ++i) {
        h[numbers.at(i)] = i;
    }
    vector<int> result;
    for (int i=0; i< numbers.size(); ++i) {
        unordered_map<int, int>::iterator it = h.find(target - numbers.at(i));
        if (it != h.end() && it->second > i) {
            result.push_back(i);
            result.push_back(it->second);
            break;
        }
    }
    return result;
}

int main() {
    vector<int> a = {-1,-2,-3,-4,-5};
    vector<int> v = twoSum(a, -8);
    for (int i: v) {
        printf("%d\n", i);
    }
}

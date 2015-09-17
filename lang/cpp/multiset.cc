#include <map>
#include <cstdio>
#include <cassert>

using namespace std;

int main() {
    multimap<int, char> M;
    M.insert(make_pair(1, 'a'));
    M.insert(make_pair(1, 'A'));
    M.insert(make_pair(1, 'b'));
    M.insert(make_pair(1, 'B'));
    assert(M.find(1) != M.end());
    auto it1 = M.find(1);
    printf("key %d: %c\n", it1->first, it1->second);
    pair<multimap<int, char>::iterator, multimap<int, char>::iterator> it = M.equal_range(1);
    for (auto v = it.first; v != it.second; ++v) {
        printf("key %d: %c\n", v->first, v->second);
    }
    return 0;
}

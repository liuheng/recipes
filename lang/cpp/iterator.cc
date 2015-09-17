#include <iterator>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    auto last = nums.end();
    auto rfirst = reverse_iterator<vector<int>::iterator>(last);
    printf("%d\n", *rfirst);
    return 0;
}

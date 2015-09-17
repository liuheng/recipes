#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int find_kth(vector<int> &nums1, vector<int> &nums2, int k) {
        if (nums1.size() < nums2.size()) return find_kth(nums2, nums1, k);
        if (nums2.empty()) return nums1.at(k-1);
        if (k == 1) return min(nums1.at(0), nums2.at(0));

        int v2 = min(int(nums2.size()), k/2);
        int v1 = k - v2;
        if (nums1.at(v1-1) == nums2.at(v2-1)) return nums1.at(v1-1);
        if (nums1.at(v1-1) > nums2.at(v2-1)) {
            vector<int> n2(nums2.begin()+v2, nums2.end());
            return find_kth(nums1, n2, k-v2);
        } else {
            vector<int> n1(nums1.begin()+v1, nums1.end());
            return find_kth(n1, nums2, k-v1);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        if (sum % 2 == 0) {
            return (find_kth(nums1, nums2, sum/2) + find_kth(nums1, nums2, sum/2+1))/2.0;
        } else {
            return find_kth(nums1, nums2, sum/2+1);
        }
    }
};

int main() {
    Solution S;
    vector<int> v1 = {1,2};
    vector<int> v2 = {1,2,3};
    printf("%f\n", S.findMedianSortedArrays(v1, v2));
    return 0;
}

#include <cstdio>
#include <string>

using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        int i = 0;
        int j = 0;
        int *next = new int[needle.length()];
        calNext(needle, next);
        for(int i=0; i<needle.length(); ++i) printf("%d ", next[i]);
        printf("\n");
        while (i < int(haystack.length()) && j < int(needle.length())) {
            if (j == -1 || haystack.at(i) == needle.at(j)) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        delete []next;
        if (j == needle.length()) return i - j;
        else return -1;
    }
private:
    void calNext(string str, int next[]) {
        int k = -1;
        next[0] = -1;
        int j = 0;
        while (j < str.length() - 1) {
            if (k == -1 || str.at(j) == str.at(k)) {
                k++;
                j++;
                if (str.at(j) == str.at(k)) {
                    next[j] = next[k];
                } else {
                    next[j] = k;
                }
            } else {
                k = next[k];
            }
        }
    }
};

int main() {
    Solution S;
    printf("%d\n", S.strStr("mississippi", "issi"));
    return 0;
}

#include <cstdio>
#include <vector>

using namespace std;

struct TreeNode {
    TreeNode()
        : left(NULL)
        , right(NULL)
        , val(-1) {};
    TreeNode *left;
    TreeNode *right;
    int val;
};

struct ListNode {
    ListNode()
        : next(NULL)
        , val(-1) {};
    ListNode *next;
    int val;
};

vector<vector<ListNode*> > listTree(BSTree *root) {

}

int main() {

}

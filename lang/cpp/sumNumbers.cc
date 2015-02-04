#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Print(vector<int> v) {
    for (auto i: v) {
        printf("%d ", i);
    }
    printf("\n");
}

int sumNumbers(TreeNode *root) {
    int sum = 0;
    vector<vector<int> > nums;
    vector<int> n;
    TreeNode *node = root;
    stack<TreeNode*> S;
    while (!S.empty() || node != NULL) {
        if (node != NULL) {
            n.push_back(node->val);
            S.push(node);
            node = node->left;
        } else {
            if (n.size() > 0) nums.push_back(n);
            Print(n);
            n.pop_back();
            node = S.top();
            S.pop();
            node = node->right;
        }
    }
    for (auto v: nums) {
        int N = v.size();
        for (int i=0; i<N; ++i) {
            sum += pow(10, N-i-1) * v[i];
        }
    }
    return sum;
}

int main() {
    TreeNode *root = new TreeNode(0);
    TreeNode *pl = new TreeNode(1);
    TreeNode *pr = new TreeNode(3);
    root->left = pl;
    root->right = pr;
    sumNumbers(root);
    return 0;
}

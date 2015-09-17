#include<cstdio>
#include<utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        pair<TreeNode*, TreeNode*> result;
        while (cur != NULL) {
            if (cur->left != NULL) {
                TreeNode *node = cur->left;
                while (node->right != NULL && node->right != cur)
                    node = node->right;
                if (node->right == NULL) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    check(result, pre, cur);
                    node->right = NULL;
                    pre = cur;
                    cur = cur->right;
                }
            } else {
                check(result, pre, cur);
                pre = cur;
                cur = cur->right;
            }
        }
        swap(result.first->val, result.second->val);
    }
private:
    void check(pair<TreeNode*, TreeNode*> &result, TreeNode *pre, TreeNode *cur) {
        if (pre != NULL && pre->val > cur->val) {
            if (result.first == NULL)
                result.first = pre;
            result.second = cur;
        }
    }
};

int main() {
    Solution S;
    TreeNode *root = new TreeNode(0);
    TreeNode *left = new TreeNode(1);
    root->left = left;
    S.recoverTree(root);
    return 0;
}

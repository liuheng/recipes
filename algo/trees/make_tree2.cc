/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <cstddef>
 #include <cstdio>
 #include <vector>

 using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    typedef vector<int>::iterator Type;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
private:
    TreeNode *buildTree(Type it1, Type it2, Type it3, Type it4) {
        if (it1 == it2 && it3 == it4) {
            return NULL;
        } else {
            int r = *it1;
        TreeNode *pr = new TreeNode(r);
        vector<int>::iterator it=it3;
        for (; it!=it4; ++it) {
            if (*it == r) {
                break;
            }
        }
        int dis = it - it3;
        pr->left = buildTree(it1+1, it1+dis+1, it3, it);
        pr->right = buildTree(it1+dis+1, it2, it+1, it4);
        return pr;
        }
    }
};

void printTree(TreeNode *p) {
    if (p == NULL) {
        return;
    }
    printf("%d\n", p->val);
    if (p->left != NULL) {
        printTree(p->left);
    }
    if (p->right != NULL) {
        printTree(p->right);
    }
}

int main() {
    vector<int> preorder = {3, 5, 6, 2, 8, 7, 4, 1, 9};
    vector<int> inorder = {5, 2, 6, 8, 3, 4, 7, 9, 1};
    Solution s;
    TreeNode *pRoot = s.buildTree(preorder, inorder);
    printTree(pRoot);
    return 0;
}

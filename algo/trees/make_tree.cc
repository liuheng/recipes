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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0 && inorder.size() == 0) {
        return NULL;
    } else {
        int r = preorder.at(0);
        TreeNode *pr = new TreeNode(r);
        vector<int>::iterator it=inorder.begin();
        for (; it!=inorder.end(); ++it) {
            if (*it == r) {
                break;
            }
        }
        int dis = it - inorder.begin();
        vector<int> pp1(preorder.begin() + 1, preorder.begin() + dis + 1);
        vector<int> pp2(preorder.begin() + dis + 1, preorder.end());
        vector<int> pi1(inorder.begin(), it);
        vector<int> pi2(it+1, inorder.end());
        pr->left = buildTree(pp1, pi1);
        pr->right = buildTree(pp2, pi2);
        return pr;
    }
}

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
    TreeNode *pRoot = buildTree(preorder, inorder);
    printTree(pRoot);
    return 0;
}

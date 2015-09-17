#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef vector<int>::iterator It;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    int val;
    TreeNode()
    : left(NULL)
    , right(NULL)
    , parent(NULL)
    , val(-1) {}
};

void preOrder(TreeNode *root) {
    stack<TreeNode*> S;
    TreeNode *cur = root;
    while (!S.empty() || cur != NULL) {
        if (cur != NULL) {
            S.push(cur);
            printf("%d ", cur->val);
            cur = cur->left;
        } else {
            cur = S.top();
            S.pop();
            cur = cur->right;
        }
    }
    printf("\n");
}

void inOrder(TreeNode *root) {
    stack<TreeNode*> S;
    TreeNode *cur = root;
    while (!S.empty() || cur != NULL) {
        if (cur != NULL) {
            S.push(cur);
            cur = cur->left;
        } else {
            cur = S.top();
            S.pop();
            printf("%d ", cur->val);
            cur = cur->right;
        }
    }
    printf("\n");
}

void postOrder(TreeNode *root) {
    stack<TreeNode*> S;
    TreeNode *cur = root;
    TreeNode *pre = NULL;
    while (!S.empty() || cur != NULL) {
        if (cur != NULL) {
            S.push(cur);
            cur = cur->left;
        } else if (S.top()->right != pre) {
            cur = S.top()->right;
            pre = NULL;
        } else {
            pre = S.top();
            S.pop();
            printf("%d ", pre->val);
        }
    }
    printf("\n");
}

TreeNode *predecessor(TreeNode *cur) {
    TreeNode *node = cur->left;
    while (node->right != NULL && node->right != cur)
        node = node->right;
    return node;
}

void preOrderM(TreeNode *root) {
    TreeNode *cur = root;
    while (cur != NULL) {
        if (cur->left != NULL) {
            TreeNode *node = predecessor(cur);
            if (node->right == NULL) {
                printf("%d ", cur->val);
                node->right = cur;
                cur = cur->left;
            } else {
                node->right = NULL;
                cur = cur->right;
            }
        } else {
            printf("%d ", cur->val);
            cur = cur->right;
        }
    }
    printf("\n");
}

void inOrderM(TreeNode *root) {
    TreeNode *cur = root;
    while (cur != NULL) {
        if (cur->left != NULL) {
            TreeNode *node = predecessor(cur);
            if (node->right == NULL) {
                node->right = cur;
                cur = cur->left;
            } else {
                printf("%d ", cur->val);
                node->right = NULL;
                cur = cur->right;
            }
        } else {
            printf("%d ", cur->val);
            cur = cur->right;
        }
    }
    printf("\n");
}

void reverse(TreeNode *from, TreeNode *to) {
    if (from == to) return;
    TreeNode *a = from;
    TreeNode *b = from->right;
    TreeNode *c = NULL;
    while (a != to) {
        c = b->right;
        b->right = a;
        a = b;
        b = c;
    }
}

void visit_reverse(TreeNode *from, TreeNode *to) {
    TreeNode *p = to;
    reverse(from, to);
    while (true) {
        printf("%d ", p->val);
        if (p == from)
            break;
        p = p->right;
    }
    reverse(to, from);
}

void postOrderM(TreeNode *root) {
    TreeNode dummy;
    dummy.left = root;
    dummy.right = NULL;
    TreeNode *cur = &dummy;
    TreeNode *pre = NULL;
    while (cur != NULL) {
        if (cur->left != NULL) {
            TreeNode *node = predecessor(cur);
            if (node->right == NULL) {
                node->right = cur;
                pre = cur;
                cur = cur->left;
            } else {
                visit_reverse(cur->left, pre);
                node->right = NULL;
                pre = cur;
                cur = cur->right;
            }
        } else {
            pre = cur;
            cur = cur->right;
        }
    }
    printf("\n");
}

void levelOrder(TreeNode *root) {
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        TreeNode *cur = Q.front();
        printf("%d ", cur->val);
        Q.pop();
        if (cur->left != NULL) Q.push(cur->left);
        if (cur->right != NULL) Q.push(cur->right);
    }
    printf("\n");
}

TreeNode *makeTree(It s1, It e1, It s2, It e2) {
    if (e1 - s1 == 0) return NULL;
    TreeNode *root = new TreeNode();
    root->val = *s1;
    if (e1 - s1 > 1) {
        int dis = find(s2, e2, *s1) - s2;
        root->left = makeTree(s1+1, s1+1+dis, s2, s2+dis);
        root->right = makeTree(s1+1+dis, e1, s2+dis+1, e2);
        if (root->left != NULL)
            root->left->parent = root;
        if (root->right != NULL)
            root->right->parent = root;
    }
    return root;
}

TreeNode *successor2(TreeNode *node) {
    if (node == NULL) return NULL;
    if (node->right != NULL) {
        node = node->right;
        while (node->left != NULL) node = node->left;
    } else {
        while (node->parent != NULL && node->parent->right == node) node = node->parent;
        if (node->parent != NULL && node->parent->left == node) node = node->parent;
        else return NULL;
    }
    return node;
}

TreeNode *predecessor2(TreeNode *node) {
    if (node == NULL) return NULL;
    if (node->left != NULL) {
        node = node->left;
        while (node->right != NULL) node = node->right;
    } else {
        while (node->parent != NULL && node->parent->left == node) node = node->parent;
        if (node->parent != NULL && node->parent->right == node) node = node->parent;
        else return NULL;
    }
    return node;
}

int main() {
    freopen("data.in", "r", stdin);
    int N = 0;
    int val = 0;
    scanf("%d", &N);
    vector<int> pre;
    vector<int> in;
    for (int i=0; i<N; ++i) {
        scanf("%d", &val);
        pre.push_back(val);
    }
    for (int i=0; i<N; ++i) {
        scanf("%d", &val);
        in.push_back(val);
    }
    TreeNode *root = makeTree(pre.begin(), pre.end(), in.begin(), in.end());
    levelOrder(root);
    preOrder(root);
    inOrder(root);
    postOrder(root);
    preOrderM(root);
    inOrderM(root);
    postOrderM(root);
    TreeNode *node = root;
    while (node->left != NULL) node = node->left;
    printf("%d ", node->val);
    while ((node = successor2(node)) != NULL) printf("%d ", node->val);
    printf("\n");
    node = root;
    while (node->right != NULL) node = node->right;
    printf("%d ", node->val);
    while ((node = predecessor2(node)) != NULL) printf("%d ", node->val);
    printf("\n");
    return 0;
}

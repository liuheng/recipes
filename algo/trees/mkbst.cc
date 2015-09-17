#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct BSTree{
    BSTree()
        : left(NULL)
        , right(NULL)
        , next(NULL)
        , val(-1) {}
    BSTree *left;
    BSTree *right;
    BSTree *next;
    int val;
};

void PrintTreeList(vector<BSTree*> result) {
    for (auto t: result) {
        while (t != NULL) {
            printf("%d ", t->val);
            t = t->next;
        }
        printf("\n");
    }
}

BSTree *mkTree(int arr[], int N) {
    if (N == 0) return NULL;
    BSTree *root = new BSTree();
    root->val = arr[0];
    BSTree *cur = root;
    BSTree *prev = NULL;
    for (int i=1; i<N; ++i) {
        cur = root;
        prev = NULL;
        while (true) {
            if (cur == NULL) {
                BSTree *node = new BSTree();
                node->val = arr[i];
                if (node->val <= prev->val) prev->left = node;
                else prev->right = node;
                break;
            }
            prev = cur;
            if (arr[i] <= cur->val) cur = cur->left;
            else cur = cur->right;
        }
    }
    return root;
}

BSTree *mkNode(int arr[], int start, int end) {
    if (start >= end) return NULL;
    BSTree *node = new BSTree();
    int mid = start + (end - start)/2;
    node->val = arr[mid];
    node->left = mkNode(arr, start, mid);
    node->right = mkNode(arr, mid+1, end);
    return node;
}

BSTree *mkTreeSorted(int arr[], int N) {
    if (N == 0) return NULL;
    return mkNode(arr, 0, N);
}

void PrintTree(BSTree *root) {
    if (root == NULL) printf("#\n");
    queue<BSTree*> current;
    queue<BSTree*> next;
    current.push(root);
    BSTree *cur = NULL;
    BSTree *dummy = new BSTree();
    while (!current.empty()) {
        while (!current.empty()) {
            cur = current.front();
            current.pop();
            if (cur->val == -1) printf("# ");
            else {
                printf("%d ", cur->val);
                if (cur->left == NULL) {
                    next.push(dummy);
                } else {
                    next.push(cur->left);
                }
                if (cur->right == NULL) {
                    next.push(dummy);
                } else {
                    next.push(cur->right);
                }
            }
        }
        printf("\n");
        swap(current, next);
    }
    delete dummy;
}

void listBSTree(BSTree *root, vector<BSTree*> &result) {
    queue<BSTree*> current;
    queue<BSTree*> next;
    current.push(root);
    BSTree *cur = NULL;
    BSTree *list_node = root;
    result.push_back(list_node);
    while (!current.empty()) {
        list_node = NULL;
        while (!current.empty()) {
            cur = current.front();
            current.pop();
            if (cur->left != NULL) {
                next.push(cur->left);
                if (list_node == NULL) {
                    list_node = cur->left;
                    result.push_back(list_node);
                } else {
                    list_node->next = cur->left;
                    list_node = cur->left;
                }
            }
            if (cur->right != NULL) {
                next.push(cur->right);
                if (list_node == NULL) {
                    list_node = cur->right;
                    result.push_back(list_node);
                } else {
                    list_node->next = cur->right;
                    list_node = cur->right;
                }
            }
        }
        if (list_node != NULL) list_node->next = NULL;
        swap(current, next);
    }
}

void listBSTree2(BSTree *root) {
    while (root) {
        BSTree *next = NULL;
        BSTree *cur = NULL;
        for (; root; root = root->next) {
            if (!next) next = root->left ? root->left : root->right;
            if (root->left) {
                if (cur) cur->next = root->left;
                cur = root->left;
            }
            if (root->right) {
                if (cur) cur->next = root->right;
                cur = root->right;
            }
        }
        cur->next = NULL;
        root = next;
    }
}

int main() {
    int arr[] = {3, 8, 1, 9, 5, 2, 4, 3, 4, 5};
    int sorted[] = {1, 1, 2, 3, 3, 4, 5, 7, 8, 8};
    vector<BSTree*> result;
    BSTree *root = mkTree(arr, 10);
    PrintTree(root);
    listBSTree(root, result);
    PrintTreeList(result);
    printf("\n");
    result.clear();
    root = mkTreeSorted(sorted, 10);
    PrintTree(root);
    listBSTree(root, result);
    PrintTreeList(result);
    return 0;
}

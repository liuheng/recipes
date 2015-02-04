#include <stack>
#include <vector>
#include <cstdio>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode*> S;
    vector<int> values;
    TreeNode *node = root;
	while (!S.empty() || node != NULL)
	{
		if (node != NULL)
		{
            values.push_back(node->val);
			S.push(node);
			node = node->left;
		}
		else
		{
			node = S.top();
			S.pop();
			node = node->right;
		}
	}
    return values;
}

int main() {
    TreeNode *root = new TreeNode(0);
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(5);
    root->left = p1;
    p1->right = p2;
    root->right = p3;
    p3->left = p4;
    p3->right = p5;

    vector<int> v = preorderTraversal(root);
    for (int i: v) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}

#pragma once
#include "../stack/stack.hpp"
#include "../queue/queue.hpp"

//ADT BSTNode
template <class T>
class BSTNode
{
public:
	BSTNode()
		: left(NULL)
		, right(NULL)
		, value(-1){}
	BSTNode *left;
	BSTNode *right;
	T value;
};

template <class T>
void Visit(BSTNode<T> *node, T *output, int &cur)
{
	error;
}

template <>
void Visit(BSTNode<int> *node, int *output, int &cur)
{
	output[cur++] = node->value;
}

template <class T>
bool Insert(BSTNode<T> *root, const T& Elem)
{
	if (root->value == -1)
	{//root为空，插入root
		root->value = Elem;
		return true;
	}
	BSTNode<T> *current = root;
	while (true)
	{
		if (Cmp(Elem, current->value) > 0)
		{
			if (current->right != NULL)
				current = current->right;
			else
			{
				BSTNode<T> *node = new BSTNode<T>;
				node->value = Elem;
				current->right = node;
				return true;
			}
		}
		else if (Cmp(Elem, current->value) < 0)
		{
			if (current->left != NULL)
				current = current->left;
			else
			{
				BSTNode<T> *node = new BSTNode<T>;
				node->value = Elem;
				current->left = node;
				return true;
			}
		}
		else
			return false;
	}
}

template <class T>
bool Remove(BSTNode<T> *root, const T& Elem)
{
	if (root->value == -1)//删除空树
		return false;
	BSTNode<T> *current = root;
	BSTNode<T> *parent = root;
	bool bLeft = true;
	while (true)
	{
		if (Cmp(Elem, current->value) > 0)
		{
			bLeft = false;
			if (current->right != NULL)
			{
				parent = current;
				current = current->right;
			}
			else
			{
				return false;
			}
		}
		else if (Cmp(Elem, current->value) < 0)
		{
			bLeft = true;
			if (current->left != NULL)
			{
				parent = current;
				current = current->left;
			}
			else
			{
				return false;
			}
		}
		else
		{//current为当前要删除的元素
			//1.寻找删除这个位置的替换元素
			BSTNode<T> *node = NULL;
			while (current->left != NULL || current->right != NULL)
			{
				node = NULL;
				parent = current;
				if (current->left != NULL)
				{//寻找左子树的最大元素
					node = current->left;
					bLeft = true;
					while (node->right != NULL)
					{
						bLeft = false;
						parent = node;
						node = node->right;
					}
				}
				else if (current->right != NULL)
				{//寻找右子树的最小元素
					node = current->right;
					bLeft = false;
					while (node->left != NULL)
					{
						bLeft = true;
						parent = node;
						node = node->left;
					}
				}
				if (node != NULL)
				{//找到了node，交换替代元素
					Swap(current->value, node->value);
					current = node;
				}
				else
				{//current已经是叶节点，断开即可
					break;
				}
			}
			if (current == root)
			{
				root->value = -1;
				return true;
			}
			if (bLeft)
				parent->left = NULL;
			else
				parent->right = NULL;
			delete node;
			return true;
		}
	}
}

//前序遍历 - 递归实现
template <class T>
void Traversal_NLR_R(BSTNode<T> *root, T *output)
{
	static int cur = 0;
	if (root == NULL)
		return;
	Visit(root, output, cur);
	Traversal_NLR_R(root->left, output);
	Traversal_NLR_R(root->right, output);
}

//前序遍历 - 非递归实现
template <class T>
void Traversal_NLR(BSTNode<T> *root, T *output)
{
	static int cur = 0;
	Stack<BSTNode<T>*> stack;
	BSTNode<T> *node = root;
	while (!stack.IsEmpty() || node != NULL)
	{
		if (node != NULL)
		{//根优先遍历，入栈，遍历左孩子
			Visit(node, output, cur);
			stack.Push(node);
			node = node->left;
		}
		else
		{//出栈，遍历右孩子
			node = stack.Pop();
			node = node->right;
		}
	}
}

//中序遍历 - 递归实现
template <class T>
void Traversal_LNR_R(BSTNode<T> *root, T *output)
{
	static int cur = 0;
	if (root == NULL)
		return;
	Traversal_LNR_R(root->left, output);
	Visit(root, output, cur);
	Traversal_LNR_R(root->right, output);
}

//中序遍历 - 非递归实现
template <class T>
void Traversal_LNR(BSTNode<T> *root, T *output)
{
	static int cur = 0;
	Stack<BSTNode<T>*> stack;
	BSTNode<T> *node = root;
	while (!stack.IsEmpty() || node != NULL)
	{
		if (node != NULL)
		{//左孩子优先
			stack.Push(node);
			node = node->left;
		}
		else
		{//出栈并遍历根，遍历右孩子
			node = stack.Pop();
			Visit(node, output, cur);
			node = node->right;
		}
	}
}

//后序遍历 - 递归实现
template <class T>
void Traversal_LRN_R(BSTNode<T> *root, T *output)
{
	static int cur = 0;
	if (root == NULL)
		return;
	Traversal_LRN_R(root->left, output);
	Traversal_LRN_R(root->right, output);
	Visit(root, output, cur);
}

//后序遍历 - 非递归实现
template <class T>
void Traversal_LRN(BSTNode<T> *root, T *output)
{
	static int cur = 0;
	Stack<BSTNode<T>*> stack;
	BSTNode<T> *node = root;
	BSTNode<T> *pre = NULL;
	/*
	pre用来保存上次弹出（遍历）的元素
	若当前栈顶的右孩子为pre，说名pre已经被visit过了，pop栈顶并visit
	否则先visit栈顶的右孩子
	注意：非递归方式的树遍历，每次visit进入新的循环
	*/
	while (!stack.IsEmpty() || node != NULL)
	{
		if (node != NULL)
		{//左孩子优先
			stack.Push(node);
			node = node->left;
		}
		else if (stack.Top()->right != pre)
		{//上次遍历的元素不是栈顶的右孩子，肯定也不是左孩子，则遍历右孩子
			node = stack.Top()->right;
			pre = NULL;//保证后续的非空右孩子优先于根遍历
		}
		else
		{//出栈并且遍历
			pre = stack.Pop();//栈顶始终比刚遍历完的元素高一层
			Visit(pre, output, cur);
		}
	}
}

//层序遍历，类似图的广度优先遍历
template <class T>
void Traversal_Layer(BSTNode<T> *root, T *output)
{
	static int cur = 0;
	BSTNode<T> *node = root;
	Queue<BSTNode<T>*> queue;
	queue.EnQueue(root);
	while (!queue.IsEmpty())
	{
		node = queue.DeQueue();
		Visit(node, output, cur);
		if (node->left != NULL)
			queue.EnQueue(node->left);
		if (node->right != NULL)
			queue.EnQueue(node->right);
	}
}

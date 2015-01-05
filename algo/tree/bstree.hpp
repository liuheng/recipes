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
	{//rootΪ�գ�����root
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
	if (root->value == -1)//ɾ������
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
		{//currentΪ��ǰҪɾ����Ԫ��
			//1.Ѱ��ɾ�����λ�õ��滻Ԫ��
			BSTNode<T> *node = NULL;
			while (current->left != NULL || current->right != NULL)
			{
				node = NULL;
				parent = current;
				if (current->left != NULL)
				{//Ѱ�������������Ԫ��
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
				{//Ѱ������������СԪ��
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
				{//�ҵ���node���������Ԫ��
					Swap(current->value, node->value);
					current = node;
				}
				else
				{//current�Ѿ���Ҷ�ڵ㣬�Ͽ�����
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

//ǰ����� - �ݹ�ʵ��
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

//ǰ����� - �ǵݹ�ʵ��
template <class T>
void Traversal_NLR(BSTNode<T> *root, T *output)
{
	static int cur = 0;
	Stack<BSTNode<T>*> stack;
	BSTNode<T> *node = root;
	while (!stack.IsEmpty() || node != NULL)
	{
		if (node != NULL)
		{//�����ȱ�������ջ����������
			Visit(node, output, cur);
			stack.Push(node);
			node = node->left;
		}
		else
		{//��ջ�������Һ���
			node = stack.Pop();
			node = node->right;
		}
	}
}

//������� - �ݹ�ʵ��
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

//������� - �ǵݹ�ʵ��
template <class T>
void Traversal_LNR(BSTNode<T> *root, T *output)
{
	static int cur = 0;
	Stack<BSTNode<T>*> stack;
	BSTNode<T> *node = root;
	while (!stack.IsEmpty() || node != NULL)
	{
		if (node != NULL)
		{//��������
			stack.Push(node);
			node = node->left;
		}
		else
		{//��ջ���������������Һ���
			node = stack.Pop();
			Visit(node, output, cur);
			node = node->right;
		}
	}
}

//������� - �ݹ�ʵ��
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

//������� - �ǵݹ�ʵ��
template <class T>
void Traversal_LRN(BSTNode<T> *root, T *output)
{
	static int cur = 0;
	Stack<BSTNode<T>*> stack;
	BSTNode<T> *node = root;
	BSTNode<T> *pre = NULL;
	/*
	pre���������ϴε�������������Ԫ��
	����ǰջ�����Һ���Ϊpre��˵��pre�Ѿ���visit���ˣ�popջ����visit
	������visitջ�����Һ���
	ע�⣺�ǵݹ鷽ʽ����������ÿ��visit�����µ�ѭ��
	*/
	while (!stack.IsEmpty() || node != NULL)
	{
		if (node != NULL)
		{//��������
			stack.Push(node);
			node = node->left;
		}
		else if (stack.Top()->right != pre)
		{//�ϴα�����Ԫ�ز���ջ�����Һ��ӣ��϶�Ҳ�������ӣ�������Һ���
			node = stack.Top()->right;
			pre = NULL;//��֤�����ķǿ��Һ��������ڸ�����
		}
		else
		{//��ջ���ұ���
			pre = stack.Pop();//ջ��ʼ�ձȸձ������Ԫ�ظ�һ��
			Visit(pre, output, cur);
		}
	}
}

//�������������ͼ�Ĺ�����ȱ���
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

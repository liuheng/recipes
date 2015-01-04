#ifndef _UTILS_H
#define _UTILS_H

#include <cassert>
#include <memory>

using namespace std;

#define ASSERT_EQUAL_ARRAY(t, s) \
{ \
	assert(memcmp(t, s, sizeof(s)) == 0); \
}

#define NUM_OF_INTS 100

//生成100个随机数字到文件ints.txt
void GenerateInts();

//读出这100个ints到内存
int *ReadInts();

//将排序好的数字写到output.txt
void WriteInts(int *pInts, int nSize);

//打印数组
void PrintInts(int *pInts, int nSize);

class IntContainer
{
public:
	IntContainer(int *pInts, const char *pSortMethod);
	~IntContainer();
	operator int*();
public:
	int *m_pInts;
	const char *m_pSortMethod;
};


//比较函数
template <class T>
int Cmp(const T &lhs, const T &rhs)
{
	assert(false);
}
//特化int比较函数
template <>
int Cmp(const int &lhs, const int &rhs);

//交换函数
template <class T>
void Swap(T &lhs, T &rhs)
{
	assert(false);
}
//特化交换函数
template <>
void Swap(int &lhs, int &rhs);

#endif

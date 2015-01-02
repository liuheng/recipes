#include <ctime>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <vector>
#include "utils.h"

using namespace std;

//生成100个随机数字到文件ints.txt
void GenerateInts()
{
	ofstream ofs("ints.txt");
	srand(static_cast<int>(time(NULL)));
	for(int i=0; i<100; ++i)
		ofs<<rand()%100<<" ";
	ofs.close();
}

//读出这100个ints到内存
int *ReadInts()
{
	ifstream ifs("ints.txt");
	int *pInts = new int[100];
// #pragma warning(push)
// #pragma warning(disable:4996)
	copy(istream_iterator<int>(ifs), istream_iterator<int>(),  pInts);
// #pragma warning(pop)
	ifs.close();
	return pInts;
}

//将排序好的数字写到output.txt
void WriteInts(int *pInts, int nSize)
{
	ofstream ofs("output.txt");
	srand(static_cast<int>(time(NULL)));
	for(int i=0; i<100; ++i)
		ofs<<pInts[i]<<" ";
	ofs.close();
}

//打印数组
void PrintInts(int *pInts, int nSize)
{
	for (int i=0; i<nSize; ++i)
		printf("%d ", pInts[i]);
	printf("\n\n");
}

IntContainer::IntContainer(int *pInts, const char *pSortMethod)
: m_pInts(NULL)
, m_pSortMethod(pSortMethod)
{
	if (pInts == NULL)
		return;
	if (m_pInts != NULL)
		delete []m_pInts;
	m_pInts = new int[NUM_OF_INTS];
	// memcpy_s(m_pInts, sizeof(int) * NUM_OF_INTS, pInts, sizeof(int) * NUM_OF_INTS);
	memcpy(m_pInts, pInts, sizeof(int) * NUM_OF_INTS);
	printf("Before %s Sort:\n", pSortMethod);
	PrintInts(m_pInts, NUM_OF_INTS);
}

IntContainer::~IntContainer()
{
	printf("After %s Sort:\n", m_pSortMethod);
	PrintInts(m_pInts, NUM_OF_INTS);
	if (m_pInts != NULL)
	{
		delete []m_pInts;
		m_pInts = NULL;
	}
}

IntContainer::operator int*()
{
	return m_pInts;
}

//特化int比较函数
template <>
int Cmp(const int &lhs, const int &rhs)
{
	return lhs - rhs;
}

//特化交换函数
template <>
void Swap(int &lhs, int &rhs)
{
	if (&lhs != &rhs)
	{
		lhs = lhs ^ rhs;
		rhs = lhs ^ rhs;
		lhs = lhs ^ rhs;
	}
}

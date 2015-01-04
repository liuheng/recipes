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

//����100��������ֵ��ļ�ints.txt
void GenerateInts();

//������100��ints���ڴ�
int *ReadInts();

//������õ�����д��output.txt
void WriteInts(int *pInts, int nSize);

//��ӡ����
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


//�ȽϺ���
template <class T>
int Cmp(const T &lhs, const T &rhs)
{
	assert(false);
}
//�ػ�int�ȽϺ���
template <>
int Cmp(const int &lhs, const int &rhs);

//��������
template <class T>
void Swap(T &lhs, T &rhs)
{
	assert(false);
}
//�ػ���������
template <>
void Swap(int &lhs, int &rhs);

#endif

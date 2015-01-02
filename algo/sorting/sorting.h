#ifndef _SORTING_H
#define _SORTING_H

#include "utils.h"
#include <cstddef>

/////////////////////////////////// �Ƚ����� ////////////////////////////////////////

//Bubble Sort - ð������
template <class T>
void BubbleSort(T *Array, int Size)
{
	for (int i=Size-2; i>0; --i)
	{//��ѭ����i��Size-2�ݼ���0
		bool bSorted = true;
		for (int j=0; j<=i; ++j)
		{//��ѭ����j��0������i
			if (Cmp(Array[j], Array[j+1]) > 0)
			{
				Swap(Array[j], Array[j+1]);
				bSorted = false;
			}
		}
		if (bSorted)
			return;//���ĳ��ѭ��û�н��������Ѿ�����
	}
}

//Selection Sort - ѡ������
template <class T>
void SelectionSort(T* Array, int Size)
{
	for (int i=0; i<Size; ++i)
	{
		T minElem = Array[i];//���ȼ�¼δ���򲿷ֵĵ�һ��Ԫ��
		int minIndex = i;    //�������
		for (int j=i+1; j<Size; ++j)
		{
			if (Cmp(minElem, Array[j]) > 0)
			{//ÿ�α�����ȥ����СԪ�أ�����¼�����
				minElem = Array[j];
				minIndex = j;
			}
		}
		if (i != minIndex)//�ж����Ƿ������Ҫ�ƶ�
			Swap(Array[i], Array[minIndex]);
	}
}

//Insertion Sort - ��������
template <class T>
void InsertionSort(T* Array, int Size)
{
	for (int i=1; i<Size; ++i)
	{//��ѭ������1��ʼ��ָ�������Ԫ��
		int Cur = Array[i];//��Ԫ�صĲ����
		int j = i - 1;
		for (; j>=0 && Cmp(Array[j], Cur)>0; --j)
		{//�Ӻ���ǰ������������������򣬱ȽϺ��ƶ��������ǳ�С�����ȽϺͽ�����ͬһ��ѭ����
			Array[j+1] = Array[j];
		}
		Array[j+1] = Cur;
	}
}

//Shell Sort - ϣ�������Եݼ���gapֵ����β��������ֽ���С��������
template <class T>
void ShellSort(T* Array, int Size)
{
	int gap = 0;
	while (gap <= Size)
	{
		gap = gap * 3 + 1;
	}
	for (; gap>=1; gap=(gap-1)/3)
	{//gapѭ����������Сgap��1
		for (int i=gap; i<Size; ++i)
		{//�򻯣����ǱȽ�++i��i-j*gap��������������ѭ���Ƚ�i+gap��i-j*gap���ⲻ���ٱȽϣ��������˴���
			int Cur = Array[i];
			int j = i - gap;
			for (; j>=0 && Cmp(Array[j], Cur)>0; j-=gap)
			{//���ɣ��ȽϺ��ƶ���ͬһѭ���н���
				Array[j+gap] = Array[j];
			}
			Array[j+gap] = Cur;
		}
	}
}

//Merge Sort - merge_array, the overlay option
template <class T>
void merge_array(T* Array, int first, int mid, int last, T* temp)
{//ÿ�ζ���Ϊ����Ϊ[first,mid]��[mid+1,last]����Ҫʹ������ҿ����䣬�������Լ�����
	int i = first;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= last)
	{
		if (Cmp(Array[i], Array[j]) <= 0)
			temp[k++] = Array[i++];
		else
			temp[k++] = Array[j++];
	}
	while (i <= mid)
		temp[k++] = Array[i++];
	while (j <= last)
		temp[k++] = Array[j++];

	for (int m=0; m<k; ++m)
		Array[first+m] = temp[m];
}

//Merge Sort - sort_array optimized substructure
template <class T>
void sort_array(T* Array, int first, int last, T* temp)
{
	if (first < last)
	{//ÿ�ζ���Ϊ����Ϊ[first,mid]��[mid+1,last]����Ҫʹ������ҿ����䣬�������Լ�����
		int mid = first/2 + last/2;
		sort_array(Array, first, mid, temp);
		sort_array(Array, mid+1, last, temp);
		merge_array(Array, first, mid, last, temp);
	}
}
//Merge Sort
template <class T>
void MergeSort(T* Array, int Size)
{
	T *temp = new T[Size];
	sort_array(Array, 0, Size-1, temp);
	delete []temp;
}

//Heap Sort - HeapifyDown��ɾ���������ɾ�������Ԫ�أ� i Ϊ��������Ԫ���±�
template <class T>
void HeapifyDown(T* Array, int i, int Size)
{//�����������ɴ�С��������
	int child = 0;
	T tmp = Array[i];//��ǰiλ�õ�ֵʼ�ձ�����tmp
	/*
	ÿ��ѭ����ǰ�ڵ�����һ�㣬
	ֱ��û�к��ӻ򸸽ڵ��Ѿ�Ϊ���������е����Ԫ�أ�ѭ����ֹ
	*/
	for (; 2*i+1 < Size; i = child)
	{//���ϴӿ��ܵ��������Ӻͱ������ҵ����ģ��滻����
		child = 2*i+1;
		if (child < Size - 1 && Cmp(Array[child+1], Array[child]) > 0)
			child++;//�ҵ���Сchild
		if (Cmp(tmp, Array[child]) < 0)//�����ǰ�ڵ�С�ڽϴ��child��������
			Array[i] = Array[child];
		else
			break;//û�б�Ҫ�����ˣ�������ڵ�������յ�
	}
	Array[i] = tmp;//�ƶ����i�㣨tmp�������Ƶ�������λ��
}

//Heap Sort
template <class T>
void HeapSort(T* Array, int Size)
{
	for (int i=Size/2; i>=0; --i)//���Ѳ�������Size/2��С��0�����ε���
		HeapifyDown(Array, i, Size);
	for (int j=Size-1; j>0; --j)
	{//DeleteMax�����������ѭ����С������д�����ÿ�ΰ����Ԫ���Ƶ�ƫĩβ�����Զ���С�ѹ�ģ
		Swap(Array[0], Array[j]);//pop max to end
		HeapifyDown(Array, 0, j);
	}
}

//Quick Sort - qsort
template <class T>
void q_sort(T* Array, int start, int end)
{//q_sort���߼��ܼ򵥣����Ǳ߽������Ĵ�����鷳��ע�⣡
	if (start >= end)
		return;//1.�˳�������ֻ��0��1��Ԫ�ش�����
	int i = start + 1;//2.��Ԫ�����ڱ�
	int j = end;
	while (i < j)
	/*
	3.���������i��jָ��һ��Ԫ�أ����˴��������������<=�������ܻ������ѭ�������к�����������������
	����������������ǲ��еģ���Ϊ©����Ԫ�ش�Сδ֪�������6.���жϱ߽�����
	*/
	{
		//4.ʹ��<=����ά��������ȶ��ԣ������ٽ�������
		//5.ʹ��i<end��j>start���жϣ���֤����while���磬4��5��������д
		while (Cmp(Array[i], Array[start]) <= 0 && i < end)
			i++;
		while (Cmp(Array[j], Array[start]) >= 0 && j > start)
			j--;
		if (i < j)//����������ʲ����еȺ�
			Swap(Array[i], Array[j]);
	}
	if (Cmp(Array[start], Array[j]) > 0)//6.���������Ҫ�жϱ߽�
		Swap(Array[j], Array[start]);
	q_sort(Array, start, j-1);
	q_sort(Array, j+1, end);
}

//Quick Sort
template <class T>
void QuickSort(T* Array, int Size)
{
	q_sort(Array, 0, Size-1);
}

/////////////////////////////////// �ǱȽ����� ////////////////////////////////////////

//Bucket Sort - bucket_element Linkedlist
template <class T>
struct bucket_element
{//ÿ��bucket���Ԫ������
	struct bucket_element<T> *next;
	T value;
};

//Bucket Sort
template <class T>
void BucketSort(T* Array, int Size)
{
	bucket_element<T> bucket[NUM_OF_INTS/10] = {0};
	for (int i=0; i<Size; ++i)
	{//��Ͱ������Ͱ������ƽ��O(N)
		int bucket_index = Array[i] / 10;
		bucket_element<T> *pHead = &(bucket[bucket_index]);//����headԪ����������
		bucket_element<T> *p = pHead;
		while (true)
		{
			if (p->next == NULL || Cmp(p->next->value, Array[i]) > 0)
			{
				bucket_element<T> *pElem = new bucket_element<T>();
				pElem->value = Array[i];
				pElem->next = p->next;
				p->next = pElem;
				break;
			}
			else
			{
				p = p->next;
			}
		}
	}

	int k = 0;
	for (int j=0; j<NUM_OF_INTS/10; ++j)
	{//����Ͱ��Ԫ�س�Ͱ��ɾ��Ͱ������ռ䣬ƽ��O(K)��KΪͰ��Ŀ
		bucket_element<T> *pHead = &(bucket[j]);
		bucket_element<T> *p = pHead->next;
		while (p != NULL)
		{
			Array[k++] = p->value;
			bucket_element<T> *pDel = p;
			p = p->next;
			delete pDel;
		}
	}
}

//Counting Sort
template <class T>
void CountingSort(T* Array, int Size)
{
	int counts[NUM_OF_INTS] = {0};
	for (int i=0; i<Size; ++i)//�������飬������O(N)
		counts[Array[i]] ++;
	int k = 0;
	for (int j=0; j<NUM_OF_INTS; ++j)//����������O(K)��KΪ��������Ŀ
	{
		while (counts[j]-- > 0)
			Array[k++] = j;
	}
}

//Radix Sort
template <class T>
void RadixSort(T* Array, int Size)
{
	int base = 1;
	int exp = 10;
	while (true)
	{
	    //�Ի��������ÿһ�������ִ��Ͱ����
		bool bSorted = true;
		bucket_element<T> bucket[10] = {0};
		for (int i=0; i<Size; ++i)
		{//��Ͱ������Ͱ������O(N)
			if (Array[i]/base != 0)
				bSorted = false;
			int bucket_index = Array[i]/base%exp;
			bucket_element<T> *pHead = &(bucket[bucket_index]);//����headԪ����������
			bucket_element<T> *p = pHead;
			while (true)
			{
				if (p->next == NULL || Cmp(p->next->value, Array[i]) > 0)
				{
					bucket_element<T> *pElem = new bucket_element<T>();
					pElem->value = Array[i];
					pElem->next = p->next;
					p->next = pElem;
					break;
				}
				else
				{
					p = p->next;
				}
			}
		}

		int k = 0;
		for (int j=0; j<10; ++j)
		{//����Ͱ��Ԫ�س�Ͱ��ɾ��Ͱ������ռ䣬O(N)
			bucket_element<T> *pHead = &(bucket[j]);
			bucket_element<T> *p = pHead->next;
			while (p != NULL)
			{
				Array[k++] = p->value;
				bucket_element<T> *pDel = p;
				p = p->next;
				delete pDel;
			}
		}
		if (bSorted)
			break;
		base *= exp;
	}
}

#endif

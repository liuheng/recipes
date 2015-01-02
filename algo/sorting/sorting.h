#ifndef _SORTING_H
#define _SORTING_H

#include "utils.h"
#include <cstddef>

/////////////////////////////////// 比较排序 ////////////////////////////////////////

//Bubble Sort - 冒泡排序
template <class T>
void BubbleSort(T *Array, int Size)
{
	for (int i=Size-2; i>0; --i)
	{//外循环，i从Size-2递减到0
		bool bSorted = true;
		for (int j=0; j<=i; ++j)
		{//内循环，j从0递增到i
			if (Cmp(Array[j], Array[j+1]) > 0)
			{
				Swap(Array[j], Array[j+1]);
				bSorted = false;
			}
		}
		if (bSorted)
			return;//如果某次循环没有交换，则已经有序
	}
}

//Selection Sort - 选择排序
template <class T>
void SelectionSort(T* Array, int Size)
{
	for (int i=0; i<Size; ++i)
	{
		T minElem = Array[i];//首先记录未排序部分的第一个元素
		int minIndex = i;    //及其序号
		for (int j=i+1; j<Size; ++j)
		{
			if (Cmp(minElem, Array[j]) > 0)
			{//每次遍历都去找最小元素，并记录其序号
				minElem = Array[j];
				minIndex = j;
			}
		}
		if (i != minIndex)//判断下是否真的需要移动
			Swap(Array[i], Array[minIndex]);
	}
}

//Insertion Sort - 插入排序
template <class T>
void InsertionSort(T* Array, int Size)
{
	for (int i=1; i<Size; ++i)
	{//外循环，从1开始，指向待插入元素
		int Cur = Array[i];//新元素的插入点
		int j = i - 1;
		for (; j>=0 && Cmp(Array[j], Cur)>0; --j)
		{//从后往前（若序列整体基本有序，比较和移动开销都非常小），比较和交换在同一个循环中
			Array[j+1] = Array[j];
		}
		Array[j+1] = Cur;
	}
}

//Shell Sort - 希尔排序（以递减的gap值做多次插入排序，又叫缩小增量排序）
template <class T>
void ShellSort(T* Array, int Size)
{
	int gap = 0;
	while (gap <= Size)
	{
		gap = gap * 3 + 1;
	}
	for (; gap>=1; gap=(gap-1)/3)
	{//gap循环，不断缩小gap到1
		for (int i=gap; i<Size; ++i)
		{//简化：总是比较++i和i-j*gap，而不是用两轮循环比较i+gap和i-j*gap，这不减少比较，但减少了代码
			int Cur = Array[i];
			int j = i - gap;
			for (; j>=0 && Cmp(Array[j], Cur)>0; j-=gap)
			{//技巧：比较和移动在同一循环中进行
				Array[j+gap] = Array[j];
			}
			Array[j+gap] = Cur;
		}
	}
}

//Merge Sort - merge_array, the overlay option
template <class T>
void merge_array(T* Array, int first, int mid, int last, T* temp)
{//每次都认为区间为[first,mid]和[mid+1,last]，不要使用左闭右开区间，这样可以简化问题
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
	{//每次都认为区间为[first,mid]和[mid+1,last]，不要使用左闭右开区间，这样可以简化问题
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

//Heap Sort - HeapifyDown，删除后调整被删处的填充元素， i 为待调整的元素下标
template <class T>
void HeapifyDown(T* Array, int i, int Size)
{//最大堆用来生成从小到大排序
	int child = 0;
	T tmp = Array[i];//当前i位置的值始终保存在tmp
	/*
	每轮循环当前节点下移一层，
	直到没有孩子或父节点已经为包括孩子中的最大元素，循环终止
	*/
	for (; 2*i+1 < Size; i = child)
	{//不断从可能的两个孩子和本身中找到最大的，替换上来
		child = 2*i+1;
		if (child < Size - 1 && Cmp(Array[child+1], Array[child]) > 0)
			child++;//找到最小child
		if (Cmp(tmp, Array[child]) < 0)//如果当前节点小于较大的child，做交换
			Array[i] = Array[child];
		else
			break;//没有必要交换了，这个父节点就是最终点
	}
	Array[i] = tmp;//移动最初i点（tmp）到下移到的最终位置
}

//Heap Sort
template <class T>
void HeapSort(T* Array, int Size)
{
	for (int i=Size/2; i>=0; --i)//建堆操作，从Size/2减小到0，依次调整
		HeapifyDown(Array, i, Size);
	for (int j=Size-1; j>0; --j)
	{//DeleteMax操作，这里的循环从小到大来写很巧妙，每次把最大元素移到偏末尾，并自动减小堆规模
		Swap(Array[0], Array[j]);//pop max to end
		HeapifyDown(Array, 0, j);
	}
}

//Quick Sort - qsort
template <class T>
void q_sort(T* Array, int start, int end)
{//q_sort的逻辑很简单，但是边界条件的处理很麻烦，注意！
	if (start >= end)
		return;//1.退出条件，只有0或1个元素待处理
	int i = start + 1;//2.首元素做哨兵
	int j = end;
	while (i < j)
	/*
	3.极限情况是i和j指向一个元素，若此处允许这种情况（<=），可能会出现死循环（所有后续条件都不进），
	而不考虑这种情况是不行的，因为漏掉的元素大小未知，因此在6.处判断边界条件
	*/
	{
		//4.使用<=，来维护排序的稳定性，并减少交换次数
		//5.使用i<end和j>start来判断，保证不会while出界，4和5必须这样写
		while (Cmp(Array[i], Array[start]) <= 0 && i < end)
			i++;
		while (Cmp(Array[j], Array[start]) >= 0 && j > start)
			j--;
		if (i < j)//这里毫无疑问不能有等号
			Swap(Array[i], Array[j]);
	}
	if (Cmp(Array[start], Array[j]) > 0)//6.因此这里需要判断边界
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

/////////////////////////////////// 非比较排序 ////////////////////////////////////////

//Bucket Sort - bucket_element Linkedlist
template <class T>
struct bucket_element
{//每个bucket里存元素链表
	struct bucket_element<T> *next;
	T value;
};

//Bucket Sort
template <class T>
void BucketSort(T* Array, int Size)
{
	bucket_element<T> bucket[NUM_OF_INTS/10] = {0};
	for (int i=0; i<Size; ++i)
	{//入桶并保持桶内有序，平均O(N)
		int bucket_index = Array[i] / 10;
		bucket_element<T> *pHead = &(bucket[bucket_index]);//保留head元素来简化问题
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
	{//遍历桶，元素出桶并删除桶内链表空间，平均O(K)，K为桶数目
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
	for (int i=0; i<Size; ++i)//遍历数组，计数，O(N)
		counts[Array[i]] ++;
	int k = 0;
	for (int j=0; j<NUM_OF_INTS; ++j)//遍历计数，O(K)，K为计数项数目
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
	    //对基数排序的每一层遍历，执行桶排序
		bool bSorted = true;
		bucket_element<T> bucket[10] = {0};
		for (int i=0; i<Size; ++i)
		{//入桶并保持桶内有序，O(N)
			if (Array[i]/base != 0)
				bSorted = false;
			int bucket_index = Array[i]/base%exp;
			bucket_element<T> *pHead = &(bucket[bucket_index]);//保留head元素来简化问题
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
		{//遍历桶，元素出桶并删除桶内链表空间，O(N)
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

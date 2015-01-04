#ifndef _BUCKET_SORT_H
#define _BUCKET_SORT_H

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

#endif

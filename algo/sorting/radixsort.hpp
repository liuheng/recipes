#ifndef _RADIX_SORT_H
#define _RADIX_SORT_H

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

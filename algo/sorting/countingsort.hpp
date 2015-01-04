#ifndef _COUNTING_SORT_H
#define _COUNTING_SORT_H

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

#endif

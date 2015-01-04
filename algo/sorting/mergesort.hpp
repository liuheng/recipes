#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H

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

#endif

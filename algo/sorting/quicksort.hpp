#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

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

#endif

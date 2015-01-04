#ifndef _SELECTION_SORT_H
#define _SELECTION_SORT_H

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

#endif

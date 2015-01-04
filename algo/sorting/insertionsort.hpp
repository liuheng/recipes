#ifndef _INSERTION_SORT_H
#define _INSERTION_SORT_H

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

#endif

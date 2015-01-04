#ifndef _BUBBLE_SORT_H
#define _BUBBLE_SORT_H

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

#endif

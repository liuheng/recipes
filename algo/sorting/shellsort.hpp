#ifndef _SHELL_SORT_H
#define _SHELL_SORT_H

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

#endif

#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H

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

#endif

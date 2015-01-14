#pragma once

#define MAX_PQUEUE_SIZE (100)

//ADT PQueue
template <class T>
class PQueue
{
public:
	PQueue()
		: end(0){}
	inline bool IsEmpty()
	{
		return end <= 0;
	}
	inline bool IsFull()
	{
		return end >= MAX_QUEUE_SIZE;
	}
	inline bool Insert(const T &Elem)
	{
		if (!IsFull())
		{
			arr[end++] = Elem;
			HeapifyUp();
			return true;
		}
		return false;
	}
	inline T GetMin()
	{
		if (!IsEmpty())
		{
			return arr[0];
		}
		else
		{
			return T();
		}
	}
	inline T ExtractMin()
	{
		if (!IsEmpty())
		{
			T tmp = arr[0];
			arr[0] = arr[--end];
			HeapifyDown();
			return tmp;
		}
		else
		{
			return T();
		}
	}
protected:
	void HeapifyUp()
	{
		int i = end-1;
		int parent = i/2;
		while (i > 0)
		{
			if (Cmp(arr[i], arr[parent]) < 0)
			{
				Swap(arr[i], arr[parent]);
				i = parent;
				parent = i/2;
			}
			else
				break;
		}
	}
	void HeapifyDown()
	{
		int i = 0;
		int child = 2*i+1;
		while (child < end)
		{
			if (child+1 < end && Cmp(arr[child], arr[child+1]) > 0)
				child++;
			if (Cmp(arr[i], arr[child]) > 0)
			{
				Swap(arr[i], arr[child]);
				i = child;
				child = 2*i+1;
			}
			else
				break;
		}
	}
private:
	T arr[MAX_QUEUE_SIZE];
	int end;
};

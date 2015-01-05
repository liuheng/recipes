#pragma once

#define MAX_QUEUE_SIZE (100)

//ADT Queue
template <class T>
class Queue
{
public:
	Queue()
		: start(0)
		, end(0){}
	inline bool IsEmpty()
	{
		return start == end;
	}
	inline bool IsFull()
	{
		return (end + 1) % MAX_QUEUE_SIZE == start;
	}
	inline bool InQueue(const T &Elem)
	{
		for (int cur=start; cur<end; cur = (cur+1)%MAX_QUEUE_SIZE)
		{
			if (arr[cur] == Elem)
				return true;
		}
		return false;
	}
	inline bool EnQueue(const T &Elem)
	{
		if (!IsFull())
		{
			arr[end] = Elem;
			end = (end + 1) % MAX_QUEUE_SIZE;
			return true;
		}
		else
		{
			return false;
		}
	}
	inline T DeQueue()
	{
		if (!IsEmpty())
		{
			T tmp = arr[start];
			start = (start + 1) % MAX_QUEUE_SIZE;
			return tmp;
		}
		else
		{
			return T();
		}
	}
private:
	T arr[MAX_QUEUE_SIZE];
	int start;
	int end;
};
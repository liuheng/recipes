#ifndef _STACK_HPP
#define _STACK_HPP

#include <sys/types.h>

#ifndef MAX_STACK_SIZE
#define MAX_STACK_SIZE (100)
#endif

//ADT Stack
template <class T>
class Stack
{
public:
	Stack()
		: stack_size(0){}
	Stack(const Stack &s)
	{
		stack_size = s.stack_size;
		memcpy_s(arr, MAX_STACK_SIZE * sizeof(T), s.arr, MAX_STACK_SIZE * sizeof(T));
	}
	Stack &operator=(const Stack &s)
	{
		stack_size = s.stack_size;
		memcpy_s(arr, MAX_STACK_SIZE * sizeof(T), s.arr, MAX_STACK_SIZE * sizeof(T));
		return *this;
	}
	inline bool Push(const T &elem)
	{
		if (stack_size < MAX_STACK_SIZE)
		{
			arr[stack_size++] = elem;
			return true;
		}
		else
		{
			return false;
		}
	}
	inline T Pop()
	{
		if (stack_size > 0)
		{
			return arr[--stack_size];
		}
		else
		{
			return -1;
		}
	}
	inline T Top()
	{
		if (stack_size > 0)
		{
			return arr[stack_size-1];
		}
		else
		{
			return -1;
		}
	}
	inline bool IsEmpty()
	{
		return stack_size == 0;
	}
	inline bool IsFull()
	{
		return stack_size == MAX_STACK_SIZE;
	}
	inline size_t Length()
	{
		return stack_size;
	}
	inline void Clear()
	{
		stack_size = 0;
	}
	T operator [](size_t i)
	{
		if (i >= stack_size)
			return T();
		else
			return arr[i];
	}

private:
	T arr[MAX_STACK_SIZE];
	size_t stack_size;
};

#endif

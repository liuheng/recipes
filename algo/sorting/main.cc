#include <cstring>
#include <cstddef>
#include "sorting.h"
#include "utils.h"

using namespace std;

int main()
{

///////////////////// SORTING ALGORITHMS BEGIN ///////////////////////////
	//GenerateInts();
	int *pInts = ReadInts();
	int nSize = NUM_OF_INTS;
	int sorted_array[NUM_OF_INTS] = {1,1,3,3,4,7,7,9,10,11,11,12,12,13,13,15,16,16,16,18,20,20,22,22,23,24,25,27,27,28,28,31,31,31,33,33,38,38,39,40,40,40,42,42,42,42,43,43,44,45,49,50,50,51,53,53,54,55,56,58,58,59,59,59,60,62,66,68,69,69,71,72,76,76,79,80,81,81,83,84,86,87,87,87,87,89,89,89,90,90,90,92,92,92,94,95,96,98,98,99};

	//√∞≈›≈≈–Ú
	{
		IntContainer obj(pInts, "Bubble");
		BubbleSort((int *)obj, nSize);
		ASSERT_EQUAL_ARRAY((int*)obj, sorted_array);
	}

	//—°‘Ò≈≈–Ú
	{
		IntContainer obj(pInts, "Selection");
		SelectionSort((int *)obj, nSize);
		ASSERT_EQUAL_ARRAY((int*)obj, sorted_array);
	}

	//≤Â»Î≈≈–Ú
	{
		IntContainer obj(pInts, "Insertion");
		InsertionSort((int *)obj, nSize);
		ASSERT_EQUAL_ARRAY((int*)obj, sorted_array);
	}

	//œ£∂˚≈≈–Ú
	{
		IntContainer obj(pInts, "Shell");
		ShellSort((int *)obj, nSize);
		ASSERT_EQUAL_ARRAY((int*)obj, sorted_array);
	}

	//πÈ≤¢≈≈–Ú
	{
		IntContainer obj(pInts, "Merge");
		MergeSort((int *)obj, nSize);
		ASSERT_EQUAL_ARRAY((int*)obj, sorted_array);
	}

	//∂—≈≈–Ú
	{
		IntContainer obj(pInts, "Heap");
		HeapSort((int *)obj, nSize);
		ASSERT_EQUAL_ARRAY((int*)obj, sorted_array);
	}

	//øÏÀŸ≈≈–Ú
	{
		IntContainer obj(pInts, "Quick");
		QuickSort((int *)obj, nSize);
		ASSERT_EQUAL_ARRAY((int*)obj, sorted_array);
	}

	//Õ∞≈≈–Ú
	{
		IntContainer obj(pInts, "Bucket");
		BucketSort((int *)obj, nSize);
		ASSERT_EQUAL_ARRAY((int*)obj, sorted_array);
	}

	//º∆ ˝≈≈–Ú
	{
		IntContainer obj(pInts, "Counting");
		CountingSort((int *)obj, nSize);
		ASSERT_EQUAL_ARRAY((int*)obj, sorted_array);
	}

	//ª˘ ˝≈≈–Ú
	{
		IntContainer obj(pInts, "Radix");
		RadixSort((int *)obj, nSize);
		ASSERT_EQUAL_ARRAY((int*)obj, sorted_array);
	}
	delete[] pInts;

///////////////////// SORTING ALGORITHMS END ///////////////////////////

	return 0;
}


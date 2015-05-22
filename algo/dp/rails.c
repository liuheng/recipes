#include <cstdio>
#include <iostream>

using namespace std;

void print_subset1(int n,int *A,int cur)	//增量构造法
{
	for(int i = 0;i < cur;i++)
		printf("%d ",A[i]);
	printf("\n");
	//确定当前元素最小可能值
	int s = cur ? A[cur-1]+1 : 0;	//当第一次调用,cur为0,s赋值0
	for(int i = s;i <= n;i++)
	{
		A[cur] = i;					//加入一个数
		print_subset1(n,A,cur+1);
	}
}

int arr[1024] = {0};

int A[5] = {1, 3, 5, 7, 9};
int main() {
	print_subset1(5, A, 1);
	return 0;
}

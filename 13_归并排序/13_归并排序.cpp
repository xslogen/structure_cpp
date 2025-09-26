// 13_归并排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//归并排序的核心思想是分治法，先递归分解数组，然后再合并数组。
//分解数组的过程是先找出数组的中间位置，然后分成左右两个数组，分别递归排序。
//合并数组的过程是先将两个有序数组合并成一个大的有序数组，然后再排序。
//归并排序的时间复杂度是O(nlogn)，空间复杂度是O(n)。
// 主要理解两个字，分治法和合并。归：必然有递的过程，并：必然有合并的过程。 先分解，再合并。

void Merge(int arr[], int begin, int mid, int end, int* p)
{
    int idx = 0;
    int i = begin;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            p[idx++] = arr[i++];
        }
        else
        {
            p[idx++] = arr[j++];
        }
    }
    while(i <= mid) p[idx++] = arr[i++];
    while(j <= end) p[idx++] = arr[j++];
    //在把合并好的大段有序的结果，拷贝到原始arr数组[begin,end]中
    for (i = begin, j = 0; i <= end; i++, j++)
    {
        arr[i] = p[j];
    }


}

void MergeSort(int arr[], int begin, int end, int* p)
{
    if (begin >= end) return;
    int mid = (begin + end) / 2;
    MergeSort(arr, begin, mid, p);
    MergeSort(arr, mid + 1, end, p);

    Merge(arr, begin, mid, end, p);
}



void MergeSort(int arr[], int size)
{
    int* p = new int[size];
    MergeSort(arr, 0, size - 1, p);
    delete[] p;
}
int main()
{
	int arr[10];
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	MergeSort(arr, 10);

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
}

// 12_快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//快速排序原理：
// 1. 选择一个基准值，通常选择第一个元素或者最后一个元素，也可以选择中间值
// 2. 将比基准值小的元素放到左边，比基准值大的元素放到右边
// 3. 对左右两边的子数组重复步骤1和步骤2，直到子数组长度为1

// 快速排序的步骤：
// 1. 选择一个基准值
// 2. 遍历数组，将小于基准值的元素放到左边，大于基准值的元素放到右边
// 3. 对左右两边的子数组重复步骤1和步骤2，直到子数组长度为1

// 快速排序的实现：
// 1. 选择一个基准值
// 2. 遍历数组，将小于基准值的元素放到左边，大于基准值的元素放到右边
// 3. 对左右两边的子数组重复步骤1和步骤2，直到子数组长度为1

// 快速排序的优化：
// 1. 三向切分：将数组分为三个部分，小于基准值的元素，等于基准值的元素，大于基准值的元素
// 2. 随机化：在选择基准值时，可以随机选择一个元素作为基准值
// 3. 尾递归：尾递归是指函数的最后一步调用另一个函数，这样可以减少栈空间的使用

// 快速排序的时间复杂度：
// 最好情况：O(nlogn)
// 最坏情况：O(n^2)
// 平均情况：O(nlogn)

// 快速排序的空间复杂度：
// 最好情况：O(logn)
// 最坏情况：O(n)
// 平均情况：O(logn)

// 快速排序的适用性：
// 1. 排序：快速排序是一种高效的排序算法，它的平均时间复杂度为O(nlogn)，是一种不稳定的排序算法。
// 2. 搜索：快速排序可以在O(logn)的时间复杂度内找到一个元素的位置。
// 3. 其他：快速排序是一种分治法的算法，它可以应用于很多领域，如排序、搜索、数据库处理、数值计算等。

int Partition(int arr[], int l, int r)
{
    int val = arr[l];

    while (l < r)
    {
        //从右边找第一个比val小的元素
        while (l < r && arr[r] > val) r--;
        if (l < r) //当前r位置的元素其实是无效了。所以下一步要从l之后位置开始找大于val的元素写到r位置
        {
            arr[l] = arr[r];
            l++;
        }
        //从l右边找第一个比val大的元素
        while (l < r && arr[l] < val) l++;
        if (l < r) //当前l位置的元素其实是无效了。所以下一步要从r之前位置开始找小于val的元素写到l位置
        {
            arr[r] = arr[l];
            r--;
        }
    }
	// l == r的位置，就是放基准数的位置
    arr[l] = val;
    return l;
}



void QuickSort(int arr[], int begin, int end)
{
    if (begin >= end) return;
	// 优化一：当[begin, end]序列的元素个数小到指定数量，采用插入排序
	//if (end - begin <= 50)
	//{
		// InsertSort(arr, begin, end);
		//return;
	//}
    int pos = Partition(arr, begin, end);
    QuickSort(arr, begin, pos - 1);
    QuickSort(arr, pos + 1, end);
}

// 快速排序
void QuickSort(int arr[], int size)
{
	return QuickSort(arr, 0, size - 1);
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

	QuickSort(arr, 10);

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
	return 0;
}


// 11_基础排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


// 冒泡排序
void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) //外层趟数
    {
        bool flag = false; //标记是否进行过交换
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1]) //内层循环，每一趟比较相邻的两个元素，如果前者大于后者，则交换位置
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true; //标记进行过交换
            }
        }
        if (!flag) return; //如果没有进行过交换，说明已经排好序，可以直接返回
    }
}
//选择排序算法 避免冒泡那么多交换，选择排序只需要进行n-1次交换，所以速度更快,选择排序是对冒泡排序的改进 
//选择排序的思路是：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
void ChoiceSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = arr[i];
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        // 找到后面剩余序列中的最小值，和开始位置的值进行交换
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
//插入排序,算法思想：每一步将一个待排序的数据插入到前面已经排好序的序列中去，直到全部插入完成。
//插入排序的基本思想是将一个数据插入到已经排好序的有序序列中，从而得到一个新的、个数加一的有序序列。
//插入排序算法的实现过程：
//1. 从第一个元素开始，该元素可以认为已经被排序；
//2. 取出下一个元素，在已经排序的元素序列中从后向前扫描；
//3. 如果该元素（已排序）大于新元素，将该元素移到下一位置；
//4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
//5. 将新元素插入到该位置后；
//6. 重复步骤2~5，直到排序完成。 打牌时，先将手中的牌按大小顺序摆好，然后再将一张牌插入到已排序的牌中，使得这张牌位于手中的牌的适当位置。
void InsertSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int val = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] <= val) break;
            arr[j + 1] = arr[j]; // 移动元素
        }
        arr[j + 1] = val; // 插入元素
    }

}
// 希尔排序,希尔排序是插入排序的一种更高效的改进版本。希尔排序是非稳定排序算法。
// 希尔排序的基本思想是：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。
// 希尔排序的基本步骤为：
// 1. 选择一个增量序列t1，t2，……，tk，其中ti>tj，tk=1；
// 2. 按增量序列个数k，对序列进行k 趟排序；
// 3. 每趟排序，根据对应的增量ti，将待排序列分割成若干子序列分别进行直接插入排序。仅增量因子为1时，整个序列作为一个表来处理，表长度即为整个序列的长度。
// 4. 重复步骤2~3，直到所有增量因子为1，即整个序列作为一个表来处理。
void ShellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int val = arr[i];
            int j = i - gap;
            for (; j >= 0; j -= gap)
            {
                if (arr[j] <= val) break;
                arr[j + gap] = arr[j]; // 移动元素
            }
            arr[j + gap] = val; // 插入元素
        }
    }
}


int main()
{
	const int COUNT = 100000;
	int* arr = new int[COUNT];
	int* brr = new int[COUNT];
	int* crr = new int[COUNT];
	int* drr = new int[COUNT];

	srand(time(NULL));

	for (int i = 0; i < COUNT; i++)
	{
		int val = rand() % COUNT;
		arr[i] = val;
		brr[i] = val;
		crr[i] = val;
		drr[i] = val;
	}

	clock_t begin, end;

	begin = clock();
	BubbleSort(arr, COUNT);
	end = clock();
	cout << "BubbleSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	ChoiceSort(brr, COUNT);
	end = clock();
	cout << "ChoiceSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	InsertSort(crr, COUNT);
	end = clock();
	cout << "InsertSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	ShellSort(drr, COUNT);
	end = clock();
	cout << "ShellSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
}

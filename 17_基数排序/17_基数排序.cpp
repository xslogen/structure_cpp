#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;


//基数排序原理 ： 
// 1. 首先，将待排序的数组分割成多个子序列，每个子序列包含相同个数的元素，且每个子序列都是有序的。
// 2. 然后，对每个子序列进行排序，使其成为一个有序序列。
// 3. 重复步骤2，直到整个数组变成有序序列。

// 基数排序的步骤：
// 1. 确定待排序的数组中最大的数的位数，并根据位数建立计数数组。
// 2. 从最低位开始，对计数数组进行计数，统计每个元素的个数。
// 3. 计算每个元素的偏移量，并将元素放入临时数组中。
// 4. 将临时数组中的元素放入原数组中。

// 基数排序的时间复杂度：
// 最坏情况下，时间复杂度为O(n*k)，其中n为待排序数组的长度，k为数组中最大的数的位数。

// 基数排序的空间复杂度：
// 空间复杂度为O(n+k)，其中n为待排序数组的长度，k为数组中最大的数的位数。

// 基数排序的稳定性：
// 基数排序是稳定的排序算法。

// 基数排序的适用性：
// 基数排序适用于整数排序，且适用于小范围内的整数排序。

// 基数排序的实现：
void RadixSort(int arr[], int size)
{
	int maxData = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (maxData < abs(arr[i]))
		{
			maxData = abs(arr[i]);
		}
	}
	int len = std::to_string(maxData).size();
	std::vector<std::vector<int>> vecs;
	int mod = 10;
	int dev = 1;

	for (int i = 0; i < len; mod *= 10, dev *= 10, i++)
	{
		vecs.resize(20); //20个痛，为了能处理负数 -9-9
		for (int j = 0; j < size; j++)
		{
			int index = arr[j] % mod / dev + 10; //去个位，十位，百位...  负数处理
			vecs[index].push_back(arr[j]);
		}
		//依次遍历所有的桶，把元素拷贝回原始的数组当中
		int idx = 0;
		for (auto& vec : vecs)
		{
			for (int v : vec)arr[idx++] = v;
		}
		vecs.clear();
	}


}

int main()
{
	int arr[10];
	srand(time(0));
	for (int i = 0; i < 10; i++) arr[i] = rand() % 100 + 1;
	arr[9] = -123;
	arr[6] = -38;

	for (int v : arr)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	RadixSort(arr, 10);
	for (int v : arr)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
	return 0;
}
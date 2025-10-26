#include <iostream>
using namespace std;
//堆的下沉
void shiftDown(int arr[], int i, int size)
{
	int val = arr[i];
	int lastfit = (size - 2) / 2;
	while (i <= lastfit)
	{
		int child = 2 * i + 1;
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child] > val)
		{
			arr[i] = arr[child];
			i = child;
		}
		else
		{
			break;
		}
	}
	arr[i] = val;
}



void HeapSort(int arr[], int size)
{
	int n = size - 1;
	//从最后一个非叶子节点开始，下沉
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		shiftDown(arr, i, size);
	}

	//把堆顶元素和末尾元素交换，从堆顶开始进行下沉。
	for (int i = n; i > 0; i--)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		shiftDown(arr, 0, i);  //最后一个元素是当前最大值
	}
}

int main()
{
	int arr[10];
	srand(time(0));
	for (int i = 0; i < 10; i++) arr[i] = rand() % 100 + 1;
	for (int v : arr)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
	HeapSort(arr, 10);
	for (int v : arr)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
	return 0;
}
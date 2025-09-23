#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// 整形数组，把偶数调整到数组的左边，把奇数调整到数组的右边
void AdjustArray(int arr[], int size)
{
	int* p = arr;
	int* q = arr + size - 1;

	while (p < q)
	{
		// p->奇数
		while (p < q)
		{
			if ((*p & 0x1) == 1)
			{
				break;
			}
			p++;
		}

		// q <- 偶数
		while (p < q)
		{
			if ((*q & 0x1) == 0)
			{
				break;
			}
			q--;
		}

		// p->奇数   q->偶数
		if (p < q)
		{
			int tmp = *p;
			*p = *q;
			*q = tmp;
			p++;
			q--;
		}
	}
}

//逆序字符串
void Reverse(char arr[], int size)
{
	char* p = arr;
	char* q = arr + size - 1;
	while (p < q)
	{
		char ch = *p;
		*p = *q;
		*q = ch;
		p++;
		q--;
	}
}



using namespace std;
class Array
{
public:
	Array(int size = 10) :
		mCur(0),
		mCap(size)
	{
		mpArr = new int[mCap]();
	}
	~Array()
	{
		delete[] mpArr;
		mpArr = nullptr;
	}

public:
	//末尾增加元素
	void push_back(int val)
	{
		if (mCur == mCap)
		{
			expand(2 * mCap);
		}
		mpArr[mCur++] = val;
	}
	//末尾删除元素
	void pop_back()
	{
		if (mCur == 0) return;
		--mCur;
	}
	// 按位置增加元素
	void  insert(int pos, int val)
	{
		if (pos < 0 || pos >=mCur) return;
		if (mCur == mCap) expand(2 * mCap);
		for (int i = mCur - 1; i >= pos; i--)
		{
			mpArr[i + 1] = mpArr[i];
		}
		mpArr[pos] = val;
		mCur++;
	}

	//按位置删除元素
	void erase(int pos)
	{
		if (pos < 0 || pos >= mCur) return;
		for(int i = pos+1;i <mCur;i++) mpArr[i-1]=mpArr[i];
		mCur--;
	}
	//元素查询
	int find(int val)
	{
		for (int i = 0; i < mCur; i++)
		{
			if (mpArr[i] == val) return i;
		}
		return -1;
	}

	void show() const
	{
		for (int i = 0; i < mCur; i++)
		{
			std::cout << mpArr[i] << " ";
		}
		std::cout << std::endl;
	}


private:
	void expand(int newCap)
	{
		int* p = new int[newCap];
		memcpy(p, mpArr, sizeof(int) * mCap);
		delete[] mpArr;
		mpArr = p;
		mCap = newCap;
	}

private:
	int* mpArr; //指向可扩容的数组内存
	int mCap;	//数组的容量
	int mCur;	//数组有效元素个数
};

int main()
{
	Array arr;

	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 100);
	}

	arr.show();
	arr.pop_back();
	arr.show();

	arr.insert(0, 100);
	arr.show();

	arr.insert(10, 200);
	arr.show();

	int pos = arr.find(100);
	if (pos != -1)
	{
		arr.erase(pos);
		arr.show();
	}
	return 0;
}
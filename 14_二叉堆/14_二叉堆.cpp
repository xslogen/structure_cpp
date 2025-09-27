// 14_二叉堆.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <functional>
#include <stdlib.h>
#include <time.h>
using namespace std;


//优先级队列实现
class PriorityQueue
{
public:
    using Comp = std::function<bool(int, int)>; //比较函数类型定义
    PriorityQueue(int cap = 20, Comp comp = std::greater<int>()):size_(0), cap_(cap), comp_(comp)
    {
        que_ = new int[cap_];
    }
    PriorityQueue(Comp comp) : size_(0), cap_(20), comp_(comp)
    {
        que_ = new int[cap_];
    }

    ~PriorityQueue()
    {
        delete[] que_;
        que_ = nullptr;
    }
private:
    //入堆上浮调整o(logn) 
    void siftUp(int i, int val)
    {
		while (i > 0) //最多计算到根节点
		{
			int f = (i - 1) / 2; //父节点位置
			if (comp_(val, que_[f]))
			{
				que_[i] = que_[f];
				i = f;
			}
			else
			{
				break;
			}
		}
		que_[i] = val;
    }

    void siftDown(int i, int val)
    {
        int lastfit = (size_ - 2) / 2; //最后一个非叶子节点的位置
        while (i <= lastfit) //最多计算到最后一个非叶子节点
        {
            int child = 2 * i + 1; //左子节点位置 
            if (child+1 < size_ && comp_(que_[child + 1], que_[child])) //右子节点存在且优先级更高
            {
                child++; //这里一定要注意右孩子节点存不存在的问题，如果右孩子不存在，那么child+1就是size_，会越界，所以要判断一下
            }
            if (comp_(que_[child], val)) //子节点优先级更高
            {
                que_[i] = que_[child];
                i = child;
            }
            else {
                break;
            }
        }
        que_[i] = val;
    }
public:
    //入堆操作 因为是数组，所以入堆操作就是数组的末尾添加元素，然后调整堆，使其满足二叉堆的性质，这个时候新元素要上浮，直到其位置正确
    void push(int val)
    {
        if (size_ == cap_)
        {
            int *p = new int[cap_ * 2];
            memcpy(p, que_, cap_ * sizeof(int));
            delete[] que_;
            que_ = p;
            cap_ *= 2;
        }
        if (size_ == 0) 
        {
            que_[size_] = val;
        }
        else
        {
            siftUp(size_, val);
        }
        size_++;
    }

    //出堆操作，就是删除堆顶元素，然后调整堆，使其满足二叉堆的性质，这个时候堆顶元素要下沉，直到其位置正确
    void pop()
    {
        if (size_ == 0) throw "container is empty";
        size_--;
        if (size_ > 0)
        {
            //删除堆顶元素，还有剩余的元素，要进行堆的下沉调整，这里没必要把最后一个元素放到堆顶，堆顶还要调整的。
            siftDown(0, que_[size_]);
        }
    }
    bool empty() const { return size_ == 0; }
    int top() const
    {
        if (size_ == 0) throw "container is empty";
        return que_[0];
    }
    int size() const { return size_; }

private:
    int* que_; //存储数据
    int size_; //数组元素的个数
    int cap_; //数组的容量
    Comp comp_; //比较函数
};

int main()
{
    //基于小根堆的优先级队列
    PriorityQueue que([](int a, int b) {return a < b; });
    srand(time(nullptr));
    for (int i = 0; i < 10; i++)
    {
        que.push(rand() % 100);
    }
    while (!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }
    cout << endl;

}


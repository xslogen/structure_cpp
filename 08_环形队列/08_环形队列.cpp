// 08_环形队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


//环形队列 数组实现 ， 入队操作：rear = (rear + 1) % cap_ ； 出队操作：front = (front + 1) % cap_
class Queue
{
public:
    Queue(int size = 10) :cap_(size), front_(0), rear_(0), size_(0)
    {
        pQue_ = new int[cap_];
    }

    ~Queue()
    {
        delete[] pQue_;
        pQue_ = nullptr;
    }
public:
    //入队 空队列 read_== front_ 那么队列满 (rear+1)%cap_ == front_ 队列满 这里要空一个位置
    void push(int val)
    {
        if ((rear_ + 1) % cap_ == front_) //队列满了
        {
            expand(2 * cap_);
        }
        pQue_[rear_] = val;
        rear_ = (rear_ + 1) % cap_;
        size_++;
    }
    //出队
    void pop()
    {
        if(front_ == rear_) throw "queue is empty"; //队列空了
        front_ = (front_ + 1) % cap_;
        size_--;
    }
    //队头元素
    int front() const {
        if(front_ == rear_) throw "queue is empty"; //队列空了
        return pQue_[front_];
    }
    //队尾元素
    int back() const
    {
        if (front_ == rear_) throw "queue is empty"; //队列空了
        return pQue_[(rear_ - 1 + cap_) % cap_];
    }
    //队列是否为空
    bool empty() const { return front_ == rear_; }

    int size() const { return size_; }
private:
    //扩容
    void expand(int size)
    {
        int* p = new int[size];
        int i = 0;
        int j = front_;
        for (; j != rear_;i++, j = (j + 1) % cap_)
        {
            p[i] = pQue_[j];
        }
        delete[] pQue_;
        pQue_ = p;
        cap_ = size;
        front_ = 0;
        rear_ = i;
    }
private:
    int* pQue_; 
    int cap_;   //空间容量
    int front_;   //队头
    int rear_;  //队尾
    int size_;  //队列元素个数
};


int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75 };
	Queue que;

	for (int v : arr)
	{
		que.push(v);
	}

	cout << que.front() << endl;
	cout << que.back() << endl;

	que.push(100);
	que.push(200);
	que.push(300);
	cout << que.front() << endl;
	cout << que.back() << endl;

	while (!que.empty())
	{
		cout << que.front() << " " << que.back() << endl;
		que.pop();
	}
}
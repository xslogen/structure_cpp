// 09_链式队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//链式队列
class LinkQueue
{
public:
    LinkQueue()
    {
        head_ = new Node();
        head_->next_ = head_;
        head_->prev_ = head_;
    }
    ~LinkQueue()
    {
        Node* p = head_->next_;
        while (p!= head_)
        {
            Node* q = p;
            p = p->next_;
            delete q;
        }
        delete head_;
    }
public:
    //入队
    void push(int val)
    {
        Node* node = new Node(val);
        node->next_ = head_;
        node->prev_ = head_->prev_;
        head_->prev_->next_ = node;
        head_->prev_ = node;
    }
    //出队
    void pop()
    {
        Node* p = head_->next_;
        if(p == head_) throw "Queue is empty";
        head_->next_ = p->next_;
        p->next_->prev_ = head_;
        delete p;
    }
    //获取队头元素
    int front() const {
        if(head_->next_ == head_) throw "Queue is empty";
        return head_->next_->data_;
    }
    //获取队尾元素
    int back() const {
        if (head_->next_ == head_) throw "Queue is empty";
        return head_->prev_->data_;
    }
    //判断队列是否为空
    bool empty() const { return head_->next_ == head_; }

private:
    struct Node
    {
        Node(int data=0):data_(data), next_(nullptr), prev_(nullptr) {}
        int data_;
        Node* next_;
        Node* prev_;
    };
    Node* head_; // 指向头节点
};

int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75 };
	LinkQueue que;

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

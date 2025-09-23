// 03_单项循环链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;



class CircleLink
{
public:
	CircleLink()
	{
		head_ = new Node();
		tail_ = head_;
		head_->next_ = head_;
	}
	~CircleLink()
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
	//尾插法
	void InsertTail(int val)
	{
		Node* node = new Node(val);
		node->next_ = tail_->next_;
		tail_->next_ = node;
		tail_ = node;
	}
	//头插法
	void InsertHead(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		head_->next_ = node;
		if (tail_ == head_)
		{
			tail_ = node;
		}
	}
	//删除节点
	void Remove(int val)
	{
		Node* q = head_;
		Node* p = head_->next_;
		while (p != head_)
		{
			if (p->data_ == val)
			{
				q->next_ = p->next_;
				delete p;
				if (q->next_ == head_)
				{
					tail_ = q;
				}
				return;
			}
			else
			{
				q = p;
				p = p->next_;
			}
		}
	}
	bool Find(int val) const
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			if (p->data_ == val) return true;
			p=p->next_;
		}
		return false;
	}

	void Show() const {
		Node* p = head_->next_;
		while (p != head_)
		{
			cout << p->data_ << " ";
			p = p->next_;
		}
		std::cout << std::endl;
	}

private:
	struct Node
	{
		Node(int data = 0) : data_(data),next_(nullptr){}
		int data_;
		Node* next_;
	};
	Node* head_; //指向头结点
	Node* tail_; //指向尾结点
};

int main()
{
	CircleLink clink;
	srand(time(NULL));

	clink.InsertHead(100);

	for (int i = 0; i < 10; i++)
	{
		clink.InsertTail(rand() % 100);
	}

	clink.InsertTail(200);
	clink.Show();

	clink.Remove(200);
	clink.Show();

	clink.InsertTail(300);
	clink.Show();
}
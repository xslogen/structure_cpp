// 04_双向链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct Node
{
	Node(int data = 0):
		data_(data),
		next_(nullptr),
		prev_(nullptr)
	{
	}
	int data_;
	Node* next_;
	Node* prev_;
};

class DoubleLink
{
public:
	DoubleLink() {
		head_ = new Node();
	}
public:
	//头插法
	void InsertHead(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		node->prev_ = head_;
		if (head_->next_)
			head_->next_->prev_ = node;
		head_->next_ = node;
	}
	//尾插法
	void InsertTail(int val)
	{
		Node* p = head_;
		while (p->next_ != nullptr) p = p->next_;

		Node* node = new Node(val);
		node->prev_ = p;
		p->next_ = node;
	}

	//删除节点
	void Remove(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				p->prev_->next_ = p->next_;
				if (p->next_)
				{
					p->next_->prev_ = p->prev_;
				}
				delete p;
				return;
			}
			p = p->next_;
		}
	}

	//节点搜索
	bool Find(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				return true;
			}
			p = p->next_;
		}
		return false;
	}
	// 链表节点输出
	void Show()
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			cout << p->data_ << " ";
			p = p->next_;
		}
		cout << endl;
	}
private:
	Node* head_; // 头指针
};
int main()
{
	DoubleLink dlink;

	dlink.InsertHead(100);

	dlink.InsertTail(20);
	dlink.InsertTail(12);
	dlink.InsertTail(78);
	dlink.InsertTail(32);
	dlink.InsertTail(7);
	dlink.InsertTail(90);
	dlink.Show();

	dlink.InsertHead(200);
	dlink.Show();

	dlink.Remove(200);
	dlink.Show();

	dlink.Remove(90);
	dlink.Show();

	dlink.Remove(78);
	dlink.Show();
}
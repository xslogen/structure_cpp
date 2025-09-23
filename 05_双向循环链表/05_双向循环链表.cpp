// 05_双向循环链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

// 定义双向链表的节点类型
struct Node
{
	Node(int data = 0)
		: data_(data)
		, next_(nullptr)
		, pre_(nullptr)
	{}
	int data_;   // 数据域
	Node* next_; // 指向下一个节点
	Node* pre_;  // 指向前一个节点
};

//双向循环链表
class DoubleCircleLink
{
public:
	DoubleCircleLink()
	{
		head_ = new Node();
		head_->next_ = head_;
		head_->pre_ = head_;
	}
	~DoubleCircleLink()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			Node* q = p->next_;
			delete p;
			p = q;
		}
		delete head_;
	}
public:
	//头插法
	void InsertHead(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		node->pre_ = head_;
		head_->next_->pre_ = node;
		head_->next_ = node;
	}

	//尾插法
	void InsertTail(int val)
	{
		Node* node = new Node(val);
		Node* p = head_->pre_;
		node->pre_ = p;
		node->next_ = head_;
		p->next_ = node;
		head_->pre_ = node;
	}

	//删除节点
	void Remove(int val)
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			if (p->data_ == val)
			{
				p->pre_->next_ = p->next_;
				p->next_->pre_ = p->pre_;
				delete p;
				return;
			}
			p = p->next_;
		}
	}
	// 节点搜索
	bool Find(int val)
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			if (p->data_ == val) return true;
			p = p->next_;
		}
		return false;
	}

	// 链表节点输出
	void Show()
	{
		Node* p = head_->next_;
		while (p != head_)
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
	DoubleCircleLink dlink;

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
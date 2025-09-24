// 07_链式栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

//TODO 游戏里面自己做了个后缀表达式求值

class LinkStack
{
public:
    LinkStack() :size_(0)
    {
        head_ = new Node();
    }
    ~LinkStack()
    {
        Node* p = head_;
        while (p != nullptr)
        {
            head_ = p->next_;
            delete p;
            p = head_;
        }
    }
public:
    //入栈 把链表头节点后面，第一个有效节点的位置，当作栈顶位置 头插
    void push(int val)
    {
        Node* p = new Node(val);
        p->next_ = head_->next_;
        head_->next_ = p;
        size_++;
    }
    //出栈 头节点后面，第一个有效节点的位置，当作栈顶位置
    void pop()
    {
        if(head_->next_ == nullptr) throw "stack is empty";
        Node* p = head_->next_;
        head_->next_ = p->next_;
        delete p;
        size_--;
    }
    //获取栈顶元素
    int top() const {
        if (head_->next_ == nullptr) throw "stack is empty";
        return head_->next_->data_;
    }
    bool empty() const { return head_->next_ == nullptr; }
    int size() const { return size_; }

private:
    struct Node
    {
        Node(int data = 0): data_(data), next_(nullptr) {}
        Node* next_;
        int data_;
    };
    Node* head_;
    int size_;
};



int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75 };
	LinkStack s;

	for (int v : arr)
	{
		s.push(v);
	}

	cout << s.size() << endl;

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;

	cout << s.size() << endl;
}


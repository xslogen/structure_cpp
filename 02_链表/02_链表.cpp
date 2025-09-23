// 02_链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Node {
    Node(int data = 0) :data_(data), next(nullptr) {}
    int data_;
    Node* next;
};

//单链表代码实现
class CLink
{
public:
    CLink()
    {
        head_ = new Node();
    }
    ~CLink()
    {
        Node* p = head_;
        while (p !=nullptr)
        {
            head_ = head_->next;
            delete p;
            p = head_;
        }
        head_ = nullptr;
    }
public:
    // 链表尾插法 O(n)   head_:头节点    tail_:尾节点 （提高效率的话，会保存尾节点tail_指针)
    void InsertTail(int val)
    {
        //先找到尾节点
        Node* p = head_;
        while(p->next !=nullptr) p = p->next;
        Node* newNode = new Node(val);
        p->next = newNode;
    }
    //链表头插
    void InsertHead(int val)
	{
		Node* newNode = new Node(val);
        newNode->next = head_->next;
        head_->next = newNode;
    }
    //链表删除节点
    void Remove(int val)
    {
        Node* p = head_->next;
        Node* q = head_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                q->next = p->next;
                delete p;
                return;
            }
            q = p;
            p = p->next;
        }
    }
    //删除多个节点
    void RemoveAll(int val)
    {
		Node* p = head_->next;
		Node* q = head_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				q->next = p->next;
				delete p;
                p = q->next;
			}
            else
            {
				q = p;
				p = p->next;
            }
			
		}
    }
    //搜索 list o(n)
    bool Find(int val)
    {
        Node* p = head_->next;
        while (p != nullptr)
        {
            if (p->data_ == val) return true;
            p = p->next;
        }
        return false;
    }

    void Show()
    {
        Node* p = head_->next;
        while (p != nullptr)
        {
            cout << p->data_ << " ";
            p = p->next;
        }
        cout << endl;
    }

private:
    Node* head_; //头指针
	friend void ReverseLink(CLink& link);
	friend bool GetLaskKNode(CLink& link, int k, int& val);
	friend void MergeLink(CLink& link1, CLink& link2);
};

//单链表逆序
void ReverseLink(CLink&  link)
{
    Node* head = link.head_;
    Node* p = head->next;
    if (p == nullptr) return;
    head->next = nullptr;
    while (p != nullptr)
    {
        Node* q = p->next;
        //头插法插入
        p->next = head->next;
        head->next = p;
        p = q;
    }
}
// 求倒数第k个节点的值 双指针法，快慢指针，快指针先走k步，然后快慢指针一起走，当快指针到达链表尾部时，慢指针指向倒数第k个节点
bool GetLaskKNode(CLink& link, int k, int& val)
{
    Node* head = link.head_;
    Node* pre = head;
    Node* p = head;

    if (k < 1) return false;
    for (int i = 0; i < k; i++)
    {
        p = p->next;
        if (p == nullptr) return false;
    }
    //pre 在头节点，p在正数第k个节点
    while (p != nullptr)
    {
        p = p->next;
        pre = pre->next;
    }
    val = pre->data_;
    return true;
}

// 合并两个有序的单链表 尾插法 O(n)
void MergeLink(CLink& link1, CLink& link2)
{
    Node* p = link1.head_->next;
    Node* q = link2.head_->next;
    Node* last = link1.head_;
    link2.head_->next = nullptr;
    while (p != nullptr && q != nullptr)
    {
        if (p->data_ < q->data_)
        {
            last->next = p;
            p = p->next;
            last = last->next;
        }
        else
        {
            last->next = q;
            q = q->next;
            last = last->next;
        }
    }
    if (p != nullptr) last->next = p;
    else last->next = q;
}



//判断单链表是否存在环，存在返回环的入口节点 快慢指针算法 快指针每次移动两步，慢指针每次移动一步，如果存在环，则快慢指针一定会相遇
bool IsLinkHasCircle(Node* head, int& val)
{
    Node* fast = head;
    Node* slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            //快慢指针相遇，说明存在环
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            val = slow->data_;
            return true;
        }
    }
    return false;
}
// 判断两个单链表是否相交，如果相交，返回相交节点的值 O(n) , 先计算长度，然后移动指针，直到指针相等
bool IsLinkHasMerge(Node* head1, Node* head2, int& val)
{
    int cnt1 = 0, cnt2 = 0;
    Node* p = head1->next;
    Node* q = head2->next;
    while (p != nullptr)
    {
        cnt1++;
        p = p->next;
    }
    while (q != nullptr)
    {
        cnt2++;
        q = q->next;
    }
    p = head1;
    q = head2;

    if (cnt1 > cnt2)
    {
        //第一个链表长
        int offset = cnt1 - cnt2;
        while (offset-- > 0)
        {
            p=p->next;
        }
    }
    else
    {
        //第二个链表长
        int offset = cnt2 - cnt1;
        while (offset-- > 0)
        {
            q = q->next;
        }
    }
    while (p != nullptr && q != nullptr)
    {
        if (p == q)
        {
            val = p->data_;
            return true;
        }
        p = p->next;
        q = q->next;
    }
    return false;
}



#if 0
int main()
{
	Node head1;
	Node n1(25), n2(67), n3(32), n4(18);
	head1.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;

	Node head2;
	Node n5(31);
	head2.next = &n5;
	n5.next = &n1;

	int val;
	if (IsLinkHasMerge(&head1, &head2, val))
	{
		cout << "链表相交，相交节点是：" << val << endl;
	}
}
#endif
#if 0
int main()
{
	int arr[] = { 25, 37, 52, 78, 88, 92, 98, 108 };
	int brr[] = { 13, 23, 40, 56, 62, 77, 109 };

	CLink link1;
	CLink link2;

	for (int v : arr)
	{
		link1.InsertTail(v);
	}

	for (int v : brr)
	{
		link2.InsertTail(v);
	}

	link1.Show();
	link2.Show();

	MergeLink(link1, link2);
	link1.Show();
	link2.Show();
}
#endif

#if 0
int main()
{
	CLink link;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int val = rand() % 100;
		link.InsertTail(val);
	}
	link.Show();

	ReverseLink(link);
	link.Show();

	int kval;
	int k = 10;
	if (GetLaskKNode(link, k, kval))
	{
		cout << "倒数第" << k << "个节点的值:" << kval << endl;
	}
}
#endif


#if 1
int main()
{
	CLink link;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int val = rand() % 100;
		link.InsertHead(val);
		cout << val << " ";
	}
	cout << endl;

	link.InsertTail(23);
	link.InsertHead(23);
	link.InsertHead(23);

	link.Show();

	link.RemoveAll(23);
	link.Show();
}
#endif

#include<iostream>
using namespace std;
typedef int datatype;
struct Lnode
{
	datatype data;
	Lnode* next;
};
typedef Lnode *link;
//链表的初始化
bool InitList(link& L)
{
	L = new Lnode;
	L->next = nullptr;
	return true;
}
//头插法创建单向链表
void CreatListHead(link& L, int n)
{
	link r = L;
	for (int i = 0; i < n; i++)
	{
		Lnode* p = new Lnode;
		cin >> p->data;
		//p->next = r->next;
		r->next = p;
		r = p;
	}
	r->next = nullptr;   //一定要有
}
//判断链表是否为空
bool IsEmpty(const link& L)
{
	if (L->next)  return false;
	else return true;
}
//销毁链表
void DestroyList(link& L)
{
	link p = L->next;
	while (p != nullptr)
	{
		link temp = p;
		p = p->next;
		delete temp;
	}
	L = nullptr;
}
//统计链表长度
int GetListLength(const link& L)
{
	int length = 0;
	link p = L->next;
	while (p != nullptr)
	{
		length++;
		p = p->next;
	}
	return length;
}
//取链表中第i个元素的值
datatype Getelem(const link& L, int i)
{
	link p = L->next;  // 从第一个实际节点开始
	int pos = 1;  // 当前遍历的位置
	while (p != nullptr && pos < i)
	{
		p = p->next;  // 移动到下一个节点
		pos++;  // 增加遍历的位置
	}
	if (p == nullptr || pos > i)  // 没有找到第 i 个节点
	{
		cerr << "The element does not exist." << endl;
		return false;
	}
	datatype e = p->data;  // 获取第 i 个节点的值
	return e;
}
//按值查找链表
link FindNode(const link& L, const datatype& value)
{
	Lnode* p = L->next;
	while (p != nullptr)
	{
		if (p->data == value)		
			return p;
		p = p->next;
	}
	return 0;  // 未找到目标值对应的节点
}
//在链表中插入元素
bool InsertList(link& L, int i, datatype value)
{
	if (i < 1)
	{
		cerr << "Invalid position" << endl;
		return false;
	}
	//创建节点
	link p = new Lnode;
	p->data = value;
	//p->next = nullptr;
	link q = L;
	int count = 0;
	while (q!=nullptr && count < i - 1)
	{
		q = q->next;
		count++;
	}
	p->next = q->next;
	q->next = p;
	return true;
}
//删除链表的某个结点
bool DeleteNode(link& L, datatype value)
{
	link p = L->next;
	link r = L;
	while (p != nullptr)
	{
		if (p->data == value)
		{
			r->next = p->next;
			delete p;
			return true;
		}
		r = p;
		p = p->next;
	}
	return false;   //未找到匹配节点
}
//单链表倒置
void ReverseList(link& L) 
{
	Lnode* prev = nullptr;      // 前一个节点指针
	Lnode* current = L->next; // 当前节点指针
	Lnode* next = nullptr;      // 下一个节点指针

	while (current != nullptr) 
	{
		next = current->next;    // 先保存下一个节点
		current->next = prev;    // 当前节点指向前一个节点，完成指针反转
		prev = current;          // 前一个节点指针向后移动
		current = next;          // 当前节点指针向后移动
	}
	L->next = prev;         // 更新头节点的 next 指针，指向原链表的最后一个节点（倒置后的第一个节点）
}
//两个有序链表的合并
void MergeList(link& La, link& Lb, link& Lc)
{
	Lnode* pa = La->next;
	Lnode* pb = Lb->next;
	//Lc = La;
	Lnode* pc = La;
	while (pa && pb)
	{
		if (pa->data <= pb->data) //尾插法，插入元素
		{
			//pc的指针域指向小元素的地址
			pc->next = pa;
			//移动pc指针，使得pc永远都指向最后链表Lc的最后一个元素
			pc = pc->next;
			//pa的元素使用过后，要向后移动pa
			pa = pa->next;
		}
		else
		{
			//pc的指针域指向小元素的地址
			pc->next = pb;
			//移动pc指针，使得pc永远都指向最后链表Lc的最后一个元素
			pc = pc->next;
			//pb的元素使用过后，要向后移动pa
			pb = pb->next;
		}
	}
	//上面的while循环执行完毕后，较长的链表还会余留一段元素，这段元素的起始地址就是pa（或pb
	pc->next = (pa ? pa : pb);
	//链表合并完毕，释放Lb的头结点
	delete Lb;
}

//链表的遍历
void TraverseList(link L) 
{
	link p = L->next;
	while (p != nullptr) 
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
	link A;
	InitList(A);
	CreatListHead(A, 5);
	//InsertList(A, 4, 8);
	ReverseList(A);
	TraverseList(A);
	cout << endl;
	cout << A->next->data<<endl;
	if (A!=nullptr) cout << "empty" << endl;
	int a = GetListLength(A);
	cout << a << endl;
	int e = Getelem(A, 3);
	cout << e << endl;
	link m=FindNode(A, 4);
	cout << m << endl;
}
#include <iostream>
using namespace std;
#define maxsize 100
typedef int elemtype;
typedef struct stacknode
{
	elemtype data;
	stacknode* next;
}*linkstack;
//初始化
void InitStack(linkstack& s)
{
	s = new stacknode;
	s->next = nullptr;
	//s->data = 0;  //头节点的数据域中保存元素的个数
}
//判栈空
bool IsEmpty(linkstack& s)
{
	if (s==NULL) return true;
	else return false;
}
//压栈
void Push(linkstack& s, elemtype e)
{
	linkstack p = new stacknode;
	p->data = e;
	p->next = s;
	s = p;
}
//弹栈
elemtype Pop(linkstack& s)
{
	elemtype e;
	linkstack p;
	if (IsEmpty(s)) return NULL;
	else
	{
		p = s;
		e = p->data;
		s = s->next;
		free(p);
		return e;
	}
}
//创建栈
void CreatStack(linkstack& s, int n)
{
	elemtype k;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		Push(s, k);
	}
}

//获取栈的元素个数
int StackLength(linkstack& s)
{
	return s->data;
}
//置空栈
bool ClearStack(linkstack& s)
{
	linkstack p = s;
	while (p != nullptr) {
		linkstack temp = p;
		p = p->next;
		delete temp;
	}
	s = nullptr; // 将栈顶指针设为 nullptr，表示栈已经被清空
	/*
	while (!IsEmpty(s)) 
	{
        Pop(s);
    }
	*/
}

//栈的遍历
void TraverseList(linkstack s)
{
	linkstack p = s;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
int main()
{
	linkstack A;
	InitStack(A);
	CreatStack(A, 3);
	TraverseList(A);
	cout << endl;
	cout << A->data << endl;
	Push(A,7);
	Pop(A);
	cout << A->data << endl;
}
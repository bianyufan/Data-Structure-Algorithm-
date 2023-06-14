#include <iostream>
using namespace std;
#define maxsize 100
typedef int elemtype;
typedef struct stacknode
{
	elemtype data;
	stacknode* next;
}*linkstack;
//��ʼ��
void InitStack(linkstack& s)
{
	s = new stacknode;
	s->next = nullptr;
	//s->data = 0;  //ͷ�ڵ���������б���Ԫ�صĸ���
}
//��ջ��
bool IsEmpty(linkstack& s)
{
	if (s==NULL) return true;
	else return false;
}
//ѹջ
void Push(linkstack& s, elemtype e)
{
	linkstack p = new stacknode;
	p->data = e;
	p->next = s;
	s = p;
}
//��ջ
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
//����ջ
void CreatStack(linkstack& s, int n)
{
	elemtype k;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		Push(s, k);
	}
}

//��ȡջ��Ԫ�ظ���
int StackLength(linkstack& s)
{
	return s->data;
}
//�ÿ�ջ
bool ClearStack(linkstack& s)
{
	linkstack p = s;
	while (p != nullptr) {
		linkstack temp = p;
		p = p->next;
		delete temp;
	}
	s = nullptr; // ��ջ��ָ����Ϊ nullptr����ʾջ�Ѿ������
	/*
	while (!IsEmpty(s)) 
	{
        Pop(s);
    }
	*/
}

//ջ�ı���
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
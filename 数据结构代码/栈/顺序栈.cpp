#include <iostream>
using namespace std;
#define maxsize 100
typedef char elemtype;
typedef struct
{
	elemtype data[maxsize];
	int top;
}sqstack,*sqstack;
//��ʼ��������ջ��
void InitStack(sqstack& s)
{
	s->top = -1;
}
//��ջ��
bool StackEmpty(sqstack& s)
{
	if (s->top == -1) return true;
	else return false;
}
//Ԫ�ؽ�ջ
bool Push(sqstack& s,elemtype x)
{
	//ջ��
	if (s->top >= maxsize - 1)  return false;
	else
	{
		s->top++;
		s->data[s->top] = x;
		return true;
	}
}
//Ԫ�س�ջ
elemtype Pop(sqstack& s)
{
	if (s->top == -1)  return NULL;
	else
	{
		s->top--;
		return s->data[s->top + 1];
	}
}
//��ջ��Ԫ��
elemtype GetTop(sqstack s)
{
	if (s->top == -1)  return NULL;
	else return s->data[s->top];

}
//����ջ������ջ��λ����Բ�������ԣ�����������˳��ջ����һ��һά���ݿռ䣬
//������ջ��ջ�׷ֱ������ڹ���ռ�����ˣ�����ջ������ռ���м����졣

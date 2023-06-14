#include <iostream>
using namespace std;
#define maxsize 100
typedef char elemtype;
typedef struct
{
	elemtype data[maxsize];
	int top;
}sqstack,*sqstack;
//初始化或者置栈空
void InitStack(sqstack& s)
{
	s->top = -1;
}
//判栈空
bool StackEmpty(sqstack& s)
{
	if (s->top == -1) return true;
	else return false;
}
//元素进栈
bool Push(sqstack& s,elemtype x)
{
	//栈满
	if (s->top >= maxsize - 1)  return false;
	else
	{
		s->top++;
		s->data[s->top] = x;
		return true;
	}
}
//元素出栈
elemtype Pop(sqstack& s)
{
	if (s->top == -1)  return NULL;
	else
	{
		s->top--;
		return s->data[s->top + 1];
	}
}
//读栈顶元素
elemtype GetTop(sqstack s)
{
	if (s->top == -1)  return NULL;
	else return s->data[s->top];

}
//共享栈：利用栈底位置相对不变的特性，可以让两个顺序栈共享一个一维数据空间，
//将两个栈的栈底分别设置在共享空间的两端，两个栈顶向共享空间的中间延伸。

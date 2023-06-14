#include<iostream>
using namespace std;
#define elemtype char
#define maxsize 1024
struct SqList
{
	elemtype* elem;   //表头指针
	int length;       //表的长度
};
//线性表的初始化
bool InitList(SqList& L)
{
	L.elem = new elemtype[maxsize];   //在堆区开辟内存
	if (!L.elem)                      //判断是否分配成功
	{
		cerr << "error" << endl;
		return false;
	}
	L.length = 0;  
	return 1;
}
//线性表的销毁
void DestroyList(SqList& L)
{
	if (L.elem)
	{
		delete[] L.elem;  //释放整个数组所占用的内存空间
		L.elem = nullptr;
	}
	L.length = 0;
}
//线性表的清空
void ClearList(SqList& L)
{
	L.length = 0;
}
//判断线性表是否为空
bool IsEmpty(const SqList& L)
{
	return L.length == 0;
}
//线性表的取值
elemtype GetElem(const SqList& L, int i)
{
	if (i<1 || i>L.length)
	{
		cerr << "out of range" << endl;
		return false;
	}
	return L.elem[i - 1];
}
//线性表的查找
int LocateList(const SqList& L, elemtype e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e) 
			return i;         //查找成功，返回下标值
	}
	return 0;         //未能找到对应元素，返回0
}
//线性表的插入
bool InsertList(SqList& L, elemtype e, int i)
{
	//判断线性表长度是否小于最大长度maxsize
	if (L.length == maxsize)
	{
		cerr << "can not insert!" << endl;
		return false;
	}
	if (i<0 || i>L.length)
	{
		cerr << "wrong insert position!" << endl;
		return false;
	}
	if (L.length > 0)
	{
		for (int j = L.length - 1; j >= i; --j)
			L.elem[j + 1] = L.elem[j];   //所有元素依次向后挪动一位
	}
	//插入元素
	L.elem[i] = e;
	L.length++;   //表长加1
	return true;
}
//线性表的删除
bool DelList(SqList& L, int i)
{
	if (L.length == 0)
	{
		cerr << "List has no length" << endl;
		return false;
	}
	if (i<0 || i>L.length)
	{
		cerr << "wrong insert position!" << endl;
		return false;
	}
	for (int j = i; j < L.length; j++)
		L.elem[j] = L.elem[j + 1];   //所有元素依次向前挪动一位
	L.length--;
	return true;
}

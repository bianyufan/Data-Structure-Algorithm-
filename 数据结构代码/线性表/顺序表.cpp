#include<iostream>
using namespace std;
#define elemtype char
#define maxsize 1024
struct SqList
{
	elemtype* elem;   //��ͷָ��
	int length;       //��ĳ���
};
//���Ա�ĳ�ʼ��
bool InitList(SqList& L)
{
	L.elem = new elemtype[maxsize];   //�ڶ��������ڴ�
	if (!L.elem)                      //�ж��Ƿ����ɹ�
	{
		cerr << "error" << endl;
		return false;
	}
	L.length = 0;  
	return 1;
}
//���Ա������
void DestroyList(SqList& L)
{
	if (L.elem)
	{
		delete[] L.elem;  //�ͷ�����������ռ�õ��ڴ�ռ�
		L.elem = nullptr;
	}
	L.length = 0;
}
//���Ա�����
void ClearList(SqList& L)
{
	L.length = 0;
}
//�ж����Ա��Ƿ�Ϊ��
bool IsEmpty(const SqList& L)
{
	return L.length == 0;
}
//���Ա��ȡֵ
elemtype GetElem(const SqList& L, int i)
{
	if (i<1 || i>L.length)
	{
		cerr << "out of range" << endl;
		return false;
	}
	return L.elem[i - 1];
}
//���Ա�Ĳ���
int LocateList(const SqList& L, elemtype e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e) 
			return i;         //���ҳɹ��������±�ֵ
	}
	return 0;         //δ���ҵ���ӦԪ�أ�����0
}
//���Ա�Ĳ���
bool InsertList(SqList& L, elemtype e, int i)
{
	//�ж����Ա����Ƿ�С����󳤶�maxsize
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
			L.elem[j + 1] = L.elem[j];   //����Ԫ���������Ų��һλ
	}
	//����Ԫ��
	L.elem[i] = e;
	L.length++;   //����1
	return true;
}
//���Ա��ɾ��
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
		L.elem[j] = L.elem[j + 1];   //����Ԫ��������ǰŲ��һλ
	L.length--;
	return true;
}

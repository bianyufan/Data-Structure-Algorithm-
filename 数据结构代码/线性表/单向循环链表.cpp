#include<iostream>
using namespace std;
typedef int datatype;
struct Lnode
{
    datatype data;
    Lnode* next;
};
typedef Lnode* link;
typedef struct CLnode
{
	datatype data;
	CLnode* next;
}*CircList;
//ѭ������ĳ�ʼ��
void InitList(CircList& L)
{
	L = new CLnode;
	L->next = L;
}
//��������
//������--------------ѭ������
//while (p)--------->while (p != L)
//while (p->next)--->while (p->next != L)

//���������Ϊѭ������
void MergeToCircularList(link& list1, link& list2) 
{
    // ������һ�������ҵ�β�ڵ�
    Lnode* tail1 = list1->next;
    while (tail1->next != nullptr) {
        tail1 = tail1->next;
    }

    // �����ڶ��������ҵ�β�ڵ�
    Lnode* tail2 = list2->next;
    while (tail2->next != nullptr) {
        tail2 = tail2->next;
    }

    // �ϲ����������ѭ������
    tail1->next = list2->next;
    tail2->next = list1->next;

    // �ͷŵڶ��������ͷ�ڵ�
    delete list2;

    // ���ڶ��������ͷ�ڵ�ָ���һ�������ͷ�ڵ�
    list2 = list1;
}

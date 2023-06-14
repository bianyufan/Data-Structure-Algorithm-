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
//循环链表的初始化
void InitList(CircList& L)
{
	L = new CLnode;
	L->next = L;
}
//结束条件
//单链表--------------循环链表
//while (p)--------->while (p != L)
//while (p->next)--->while (p->next != L)

//两单链表合为循环链表
void MergeToCircularList(link& list1, link& list2) 
{
    // 遍历第一个链表，找到尾节点
    Lnode* tail1 = list1->next;
    while (tail1->next != nullptr) {
        tail1 = tail1->next;
    }

    // 遍历第二个链表，找到尾节点
    Lnode* tail2 = list2->next;
    while (tail2->next != nullptr) {
        tail2 = tail2->next;
    }

    // 合并两个链表成循环链表
    tail1->next = list2->next;
    tail2->next = list1->next;

    // 释放第二个链表的头节点
    delete list2;

    // 将第二个链表的头节点指向第一个链表的头节点
    list2 = list1;
}

#include<iostream>
using namespace std;
typedef int datatype;
typedef struct Dnode
{
    datatype data;
    Dnode* prior, * next;
} *Dlink;
//初始化
void InitList(Dlink& L)
{
    L = new Dnode;
    L->prior = nullptr;
    L->next = nullptr;
}
//头插法创建双向链表
void CreatDListHead(Dlink& L, int n)
{
    Dlink r = L;
    for (int i = 0; i < n; i++)
    {
        Dlink p = new Dnode;
        cin >> p->data;
        p->prior = r;
        p->next = r->next;
        r->next = p;
    }
}
//在双向链表的第i个位置插入元素
bool ListInsert(Dlink& L, int i, datatype e)
{
    Dlink p = L->next;
    int j = 1;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }
    Dlink s = new Dnode;
    s->data = e;
    //重新建立链接关系
    s->prior = p->prior; //第一步：s的前趋等于p的前趋
    p->prior->next = s;  //第二步，用p的前趋结点的next指向插入元素s，更改了第一条链
    s->next = p;         //第三步：s的后继指向p
    p->prior = s;        //第四步：p的前趋改为指向s，更改了第二条链
    //return
    return true;
}
//删除双向链表中的某个元素
bool Ddelete(Dlink& L, int i)
{
    Dlink p = L->next;
    int j = 1;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }
    //改变链接关系
    p->prior->next = p->next;//p的前趋结点的next等于p的后继
    if ((p->next))//如果删除的不是最后一个元素
    {
        p->next->prior = p->prior;
    }
    //释放p
    delete p;
    //结束
    return true;
}
int main()
{
    Dlink A;
    InitList(A);
    CreatDListHead(A, 5);
    cout << A->next->data << endl;
}
#include<iostream>
using namespace std;
typedef int datatype;
typedef struct Dnode
{
    datatype data;
    Dnode* prior, * next;
} *Dlink;
//��ʼ��
void InitList(Dlink& L)
{
    L = new Dnode;
    L->prior = nullptr;
    L->next = nullptr;
}
//ͷ�巨����˫������
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
//��˫������ĵ�i��λ�ò���Ԫ��
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
    //���½������ӹ�ϵ
    s->prior = p->prior; //��һ����s��ǰ������p��ǰ��
    p->prior->next = s;  //�ڶ�������p��ǰ������nextָ�����Ԫ��s�������˵�һ����
    s->next = p;         //��������s�ĺ��ָ��p
    p->prior = s;        //���Ĳ���p��ǰ����Ϊָ��s�������˵ڶ�����
    //return
    return true;
}
//ɾ��˫�������е�ĳ��Ԫ��
bool Ddelete(Dlink& L, int i)
{
    Dlink p = L->next;
    int j = 1;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }
    //�ı����ӹ�ϵ
    p->prior->next = p->next;//p��ǰ������next����p�ĺ��
    if ((p->next))//���ɾ���Ĳ������һ��Ԫ��
    {
        p->next->prior = p->prior;
    }
    //�ͷ�p
    delete p;
    //����
    return true;
}
int main()
{
    Dlink A;
    InitList(A);
    CreatDListHead(A, 5);
    cout << A->next->data << endl;
}
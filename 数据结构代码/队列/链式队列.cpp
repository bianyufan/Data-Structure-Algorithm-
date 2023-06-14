#include<iostream>
using namespace std;
#define maxsize 100
typedef int elemtype;
struct Qnode
{
    elemtype data;
    Qnode* next;
};
struct LinkQueue //�ٶ���һ�������������ͣ�һ���Խ�������Qnodeָ��
{
    Qnode* front; //ͷָ��
    Qnode* rear;  //βָ��
};
//��ʼ��
void InitQueue(LinkQueue& Q)
{
    Q.front = Q.rear = new Qnode;
    Q.front->next = nullptr;
    Q.rear = Q.front;
}
//����
void EnQueue(LinkQueue& Q, elemtype e)
{
    Qnode* p = new Qnode;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
}
//��������
void CreatQueue(LinkQueue& Q, int n)
{
    cout << "input msg" << endl;
    elemtype input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        EnQueue(Q, input);
    }
}
//����
bool EraseQueue(LinkQueue& Q)
{
    //�����ͷ���ڶ�β����������û��Ԫ�أ���ִ�иó���
    if (Q.front->next == nullptr)
    {
        cerr << "no elem to erase" << endl;
        return false;
    }
    Qnode* p = Q.front->next;
    Q.front->next = p->next;
    delete p;
    return true;
}
//��ӡ����
void PrintQueue(LinkQueue& Q)
{
    Qnode* p = Q.front->next;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
#include<iostream>
using namespace std;
#define maxsize 100
typedef int elemtype;
struct Qnode
{
    elemtype data;
    Qnode* next;
};
struct LinkQueue //再定义一个抽象数据类型，一次性建立两个Qnode指针
{
    Qnode* front; //头指针
    Qnode* rear;  //尾指针
};
//初始化
void InitQueue(LinkQueue& Q)
{
    Q.front = Q.rear = new Qnode;
    Q.front->next = nullptr;
    Q.rear = Q.front;
}
//进队
void EnQueue(LinkQueue& Q, elemtype e)
{
    Qnode* p = new Qnode;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
}
//创建链队
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
//出队
bool EraseQueue(LinkQueue& Q)
{
    //如果队头等于队尾，表明队里没有元素，不执行该程序
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
//打印链队
void PrintQueue(LinkQueue& Q)
{
    Qnode* p = Q.front->next;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
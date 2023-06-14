#include<iostream>
using namespace std;
#define maxsize 100
typedef int elemtype;
typedef struct Qnode
{
    elemtype* elem;
    int front;
    int rear;
}*Queue;
void InitQueue(Queue& Q)
{
    Q->elem = new elemtype[maxsize];
    Q->front = Q->rear = 0;
}
//置队空
void ClearQueue(Queue& Q)
{
    Q->front = Q->rear = 0;
}
//判队空
bool IsEmpty(Queue Q)
{
    if (Q->front == Q->rear) return true;
    else return false;
}
//判队满
bool IsFull(Queue Q)
{
    return (Q->rear + 1) % maxsize == Q->front;
}
//求队列的元素个数
int GetLength(Queue Q)
{
    return (Q->rear - Q->front + maxsize) % maxsize;
}
//进队
bool InsertQueue(Queue Q, elemtype e)
{
    //如果队尾+1等于队头，表明队已经满了（该队列是少用一个空间的循环队列，满队和空队的判断条件不一致）
    if (IsFull(Q))
    {
        cerr << "full of Queue" << endl;
        return false;
    }
    Q->elem[Q->rear] = e;
    Q->rear = (Q->rear + 1) % maxsize;
    return true;
}
//批量进队
void CreatQueue(Queue Q, int n)
{
    cout << "input msg" << endl;
    elemtype input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        InsertQueue(Q, input);
    }
}
//出队
bool EraseQueue(Queue Q)
{
    //如果队头等于队尾，表明队里没有元素，不执行该程序
    if (IsEmpty(Q))
    {
        cerr << "no elem to erase" << endl;
        return false;
    }
    //e = Q->elem[Q->front];
    Q->front = (Q->front + 1) % maxsize;
    return true;
}
//打印队列
void PrintQueue(Queue Q)
{
    cout << "Queue:" << endl;
    for (auto i = Q->front; i != Q->rear; i = (i + 1) % maxsize)
    {
        cout << Q->elem[i] << endl;
    }
}
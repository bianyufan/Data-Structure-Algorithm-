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
//�öӿ�
void ClearQueue(Queue& Q)
{
    Q->front = Q->rear = 0;
}
//�жӿ�
bool IsEmpty(Queue Q)
{
    if (Q->front == Q->rear) return true;
    else return false;
}
//�ж���
bool IsFull(Queue Q)
{
    return (Q->rear + 1) % maxsize == Q->front;
}
//����е�Ԫ�ظ���
int GetLength(Queue Q)
{
    return (Q->rear - Q->front + maxsize) % maxsize;
}
//����
bool InsertQueue(Queue Q, elemtype e)
{
    //�����β+1���ڶ�ͷ���������Ѿ����ˣ��ö���������һ���ռ��ѭ�����У����ӺͿնӵ��ж�������һ�£�
    if (IsFull(Q))
    {
        cerr << "full of Queue" << endl;
        return false;
    }
    Q->elem[Q->rear] = e;
    Q->rear = (Q->rear + 1) % maxsize;
    return true;
}
//��������
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
//����
bool EraseQueue(Queue Q)
{
    //�����ͷ���ڶ�β����������û��Ԫ�أ���ִ�иó���
    if (IsEmpty(Q))
    {
        cerr << "no elem to erase" << endl;
        return false;
    }
    //e = Q->elem[Q->front];
    Q->front = (Q->front + 1) % maxsize;
    return true;
}
//��ӡ����
void PrintQueue(Queue Q)
{
    cout << "Queue:" << endl;
    for (auto i = Q->front; i != Q->rear; i = (i + 1) % maxsize)
    {
        cout << Q->elem[i] << endl;
    }
}
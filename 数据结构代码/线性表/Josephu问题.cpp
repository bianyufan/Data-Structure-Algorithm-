#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
};
// 创建循环链表
void CreateCircularList(Node*& head, int n) 
{
    head = nullptr;
    Node* tail = nullptr;
    for (int i = 1; i <= n; ++i)
    {
        Node* newNode = new Node;
        newNode->data = i;
        if (head == nullptr) 
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head; // 将尾节点的 next 指针指向头节点，构成循环链表
}
// 解决约瑟夫问题
void JosephusProblem(Node*& head, int k, int m)
{
    if (head == nullptr || k <= 0 || m <= 0) 
    {
        return;
    }
    Node* p = head;
    // 找到起始位置的节点
    for (int i = 1; i < k; ++i) 
    {
        p = p->next;
    }
    while (p->next != p) 
    {
        // 找到第 m-1 个节点
        for (int i = 1; i < m - 1; ++i) 
        {
            p = p->next;
        }
        // 删除第 m 个节点
        Node* temp = p->next;
        p->next = temp->next;
        cout << temp->data << " ";
        delete temp;
        p = p->next; // 下一个节点开始报数
    }
    // 最后一个节点出列
    cout << p->data << " ";
    delete p;
    head = nullptr; // 更新头节点指针为空
}
int main() 
{
    int n, k, m;
    cout << "请输入总人数 n：";
    cin >> n;
    cout << "请输入起始位置 k：";
    cin >> k;
    cout << "请输入报数间隔 m：";
    cin >> m;

    Node* head = nullptr;
    CreateCircularList(head, n);

    cout << "出列顺序：";
    JosephusProblem(head, k, m);

    return 0;
}

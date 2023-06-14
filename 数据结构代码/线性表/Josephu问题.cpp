#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
};
// ����ѭ������
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
    tail->next = head; // ��β�ڵ�� next ָ��ָ��ͷ�ڵ㣬����ѭ������
}
// ���Լɪ������
void JosephusProblem(Node*& head, int k, int m)
{
    if (head == nullptr || k <= 0 || m <= 0) 
    {
        return;
    }
    Node* p = head;
    // �ҵ���ʼλ�õĽڵ�
    for (int i = 1; i < k; ++i) 
    {
        p = p->next;
    }
    while (p->next != p) 
    {
        // �ҵ��� m-1 ���ڵ�
        for (int i = 1; i < m - 1; ++i) 
        {
            p = p->next;
        }
        // ɾ���� m ���ڵ�
        Node* temp = p->next;
        p->next = temp->next;
        cout << temp->data << " ";
        delete temp;
        p = p->next; // ��һ���ڵ㿪ʼ����
    }
    // ���һ���ڵ����
    cout << p->data << " ";
    delete p;
    head = nullptr; // ����ͷ�ڵ�ָ��Ϊ��
}
int main() 
{
    int n, k, m;
    cout << "������������ n��";
    cin >> n;
    cout << "��������ʼλ�� k��";
    cin >> k;
    cout << "�����뱨����� m��";
    cin >> m;

    Node* head = nullptr;
    CreateCircularList(head, n);

    cout << "����˳��";
    JosephusProblem(head, k, m);

    return 0;
}

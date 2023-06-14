#include<iostream>
#include<stack>
#include<queue>
using namespace std;
//�ڵ���������
typedef struct Bnode
{
	char data;
	struct Bnode* Lchild;
	struct Bnode* Rchild;
}Btree, * Btree;
Btree CreatBinaryTree()
{
	char c;
	cin >> c;
	if (c == '#') return nullptr;
	Btree p = new Bnode;
	p->data = c;
	p->Lchild = CreatBinaryTree();
	p->Rchild = CreatBinaryTree();
}
//�ݹ����
//ǰ�����
void PreOrder(Bnode* p)
{
	if (p != NULL)
	{
		cout << p->data << " ";   //��
		PreOrder(p->Lchild);    //��
		PreOrder(p->Rchild);   //��
	}
}
//�������
void InOrder(Bnode* p)
{
	if (p != NULL)
	{
		InOrder(p->Lchild);   //��
		cout << p->data << " ";  //��
		InOrder(p->Rchild);  //��
	}
}
//�������
void PassOrder(Bnode* p)
{
	if (p != NULL)
	{
		PassOrder(p->Lchild);
		PassOrder(p->Rchild);
		cout << p->data << " ";
	}
}
//�ǵݹ��㷨
//ǰ��
void PreOrder1(Btree T)
{
	if (T == NULL) return;
	stack<Btree>s;
	s.push(T);
	while (!s.empty())
	{
		Btree p = s.top();
		s.pop();
		while (p != NULL)
		{
			cout << p->data;
			if (p->Rchild)
				s.push(p->Rchild);
			p = p->Lchild;
		}
	}
}
//��һ���汾
// ����һ����ջ�������ڵ�ѹ��ջ�С�
// ѭ��ִ�����²��裬ֱ��ջΪ�գ�
// ����ջ���ڵ㣬�����ʸýڵ㡣
// ���ýڵ���������������������ڵ�ѹ��ջ�С�
// ���ýڵ���������������������ڵ�ѹ��ջ�С�
// ��ɱ�����
void PreOrderTraversal(Btree p) {
    if (p == NULL) {
        return;
    }

    stack<Btree> s;
    s.push(p);

    while (!s.empty()) {
        Btree node = s.top();
        s.pop();
        
        // ���ʵ�ǰ�ڵ�
        cout << node->data << " ";

        // �Ƚ��������ڵ�ѹ��ջ
        if (node->Rchild != NULL) {
            s.push(node->Rchild);
        }

        // �ٽ��������ڵ�ѹ��ջ
        if (node->Lchild != NULL) {
            s.push(node->Lchild);
        }
    }
}

//����
void InOrder1(Btree p)
{
	if (p == NULL) return;
	stack<Btree>s;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->Lchild;
		}
		p = s.top();   //ȡջ��ָ��
		s.pop();
		cout << p->data;
		p = p->Rchild;
		cout << endl;
	}
}
//
// ����һ����ջ��һ��ָ�룬��ʼʱָ����ڵ㡣
// ѭ��ִ�����²��裬ֱ��ջΪ����ָ��Ϊ�գ�
// ����ǰ�ڵ㲻Ϊ�գ�����ǰ�ڵ���ջ������ָ���������������������������
// ����ǰ�ڵ�Ϊ�գ�˵���Ѿ���������ߵ�Ҷ�ӽڵ㣬��ʱ����ջ���ڵ㲢���ʣ�Ȼ��ָ���������������������ұ�����
// ��ɱ�����
void InOrderTraversal(Btree p) {
    stack<Btree> s;
    Btree curr = p;

    while (!s.empty() || curr != NULL) {
        if (curr != NULL) {
            s.push(curr);
            curr = curr->Lchild;  // ������������
        } else {
            curr = s.top();
            s.pop();
            
            // ���ʵ�ǰ�ڵ�
            cout << curr->data << " ";
            
            curr = curr->Rchild;  // ������������
        }
    }
}

//����
void PassOrder1(Btree p)
{
	if (p == NULL)return;
	stack<Btree>s;
	Bnode* tag = NULL;   //tagָ���൱��һ����ƨ��  ����ʹ��Ǹ�ָ�� �Ҿ�ָ���ĸ�ָ��
	while (p != NULL || !s.empty())   //ʣ�µ�˼·�������������һëһ��
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->Lchild;
		}
		p = s.top();
		s.pop();
		if (p->Rchild == NULL || p->Rchild == tag)
		{
			cout << p->data;
			tag = p;
			p = NULL;
		}
		else
		{
			s.push(p);
			p = p->Rchild;
		}
	}
	cout << endl;
}
//����α���������
void LayerOrder(Btree T)
{
	if (T == NULL)  return;
	queue<Btree>Q;
	Q.push(T);
	while (!Q.empty())
	{
		Btree p = Q.front();
		Q.pop();
		cout << p->data << " ";
		if (p->Lchild != NULL) Q.push(p->Lchild);
		if (p->Rchild != NULL)Q.push(p->Rchild);
	}
}
//������������
int Depth(Btree T)
{
	if (T == nullptr)
	{
		return 0;
	}
	int m = Depth(T->Lchild);
	int n = Depth(T->Rchild);
	if (m > n)
		return m + 1;
	else
		return n + 1;
}
//���
int DepthofBT(Btree T)
{
	if (T == nullptr)
	{
		return 0;
	}
	return max(DepthofBT(T->Lchild), DepthofBT(T->Rchild)) + 1;
}
//��������Ľ����
int CountNode(Btree T)
{
	if (T == nullptr)
	{
		return 0;
	}
	// //L
	// int m = CountNode(T->lchild);
	// //R
	// int n = CountNode(T->rchild);
	// //
	// return m + n + 1;
	//���Ӽ򵥵����
	return CountNode(T->Lchild) + CountNode(T->Rchild) + 1;
}
//���������Ҷ�ӽ����
int Count0Node(Btree T)
{
	if (T == nullptr)
	{
		return 0;
	}
	if (T->Lchild == nullptr && T->Rchild == nullptr)
	{
		return 1;
	}
	return Count0Node(T->Lchild) + Count0Node(T->Rchild);
}

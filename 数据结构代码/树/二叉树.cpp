#include<iostream>
#include<stack>
#include<queue>
using namespace std;
//节点类型描述
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
//递归遍历
//前序遍历
void PreOrder(Bnode* p)
{
	if (p != NULL)
	{
		cout << p->data << " ";   //中
		PreOrder(p->Lchild);    //左
		PreOrder(p->Rchild);   //右
	}
}
//中序遍历
void InOrder(Bnode* p)
{
	if (p != NULL)
	{
		InOrder(p->Lchild);   //左
		cout << p->data << " ";  //中
		InOrder(p->Rchild);  //右
	}
}
//后序遍历
void PassOrder(Bnode* p)
{
	if (p != NULL)
	{
		PassOrder(p->Lchild);
		PassOrder(p->Rchild);
		cout << p->data << " ";
	}
}
//非递归算法
//前序
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
//另一个版本
// 创建一个空栈，将根节点压入栈中。
// 循环执行以下步骤，直到栈为空：
// 弹出栈顶节点，并访问该节点。
// 若该节点存在右子树，将右子树节点压入栈中。
// 若该节点存在左子树，将左子树节点压入栈中。
// 完成遍历。
void PreOrderTraversal(Btree p) {
    if (p == NULL) {
        return;
    }

    stack<Btree> s;
    s.push(p);

    while (!s.empty()) {
        Btree node = s.top();
        s.pop();
        
        // 访问当前节点
        cout << node->data << " ";

        // 先将右子树节点压入栈
        if (node->Rchild != NULL) {
            s.push(node->Rchild);
        }

        // 再将左子树节点压入栈
        if (node->Lchild != NULL) {
            s.push(node->Lchild);
        }
    }
}

//中序
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
		p = s.top();   //取栈顶指针
		s.pop();
		cout << p->data;
		p = p->Rchild;
		cout << endl;
	}
}
//
// 创建一个空栈和一个指针，初始时指向根节点。
// 循环执行以下步骤，直到栈为空且指针为空：
// 若当前节点不为空，将当前节点入栈，并将指针移向左子树，继续向左遍历。
// 若当前节点为空，说明已经到达最左边的叶子节点，此时弹出栈顶节点并访问，然后将指针移向右子树，继续向右遍历。
// 完成遍历。
void InOrderTraversal(Btree p) {
    stack<Btree> s;
    Btree curr = p;

    while (!s.empty() || curr != NULL) {
        if (curr != NULL) {
            s.push(curr);
            curr = curr->Lchild;  // 向左子树遍历
        } else {
            curr = s.top();
            s.pop();
            
            // 访问当前节点
            cout << curr->data << " ";
            
            curr = curr->Rchild;  // 向右子树遍历
        }
    }
}

//后序
void PassOrder1(Btree p)
{
	if (p == NULL)return;
	stack<Btree>s;
	Bnode* tag = NULL;   //tag指针相当于一个跟屁虫  你访问过那个指针 我就指向哪个指针
	while (p != NULL || !s.empty())   //剩下的思路和中序遍历几乎一毛一样
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
//按层次遍历二叉树
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
//求二叉树的深度
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
//深度
int DepthofBT(Btree T)
{
	if (T == nullptr)
	{
		return 0;
	}
	return max(DepthofBT(T->Lchild), DepthofBT(T->Rchild)) + 1;
}
//求二叉树的结点数
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
	//更加简单的语句
	return CountNode(T->Lchild) + CountNode(T->Rchild) + 1;
}
//求二叉树的叶子结点数
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

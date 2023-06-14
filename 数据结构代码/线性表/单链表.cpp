#include<iostream>
using namespace std;
typedef int datatype;
struct Lnode
{
	datatype data;
	Lnode* next;
};
typedef Lnode *link;
//����ĳ�ʼ��
bool InitList(link& L)
{
	L = new Lnode;
	L->next = nullptr;
	return true;
}
//ͷ�巨������������
void CreatListHead(link& L, int n)
{
	link r = L;
	for (int i = 0; i < n; i++)
	{
		Lnode* p = new Lnode;
		cin >> p->data;
		//p->next = r->next;
		r->next = p;
		r = p;
	}
	r->next = nullptr;   //һ��Ҫ��
}
//�ж������Ƿ�Ϊ��
bool IsEmpty(const link& L)
{
	if (L->next)  return false;
	else return true;
}
//��������
void DestroyList(link& L)
{
	link p = L->next;
	while (p != nullptr)
	{
		link temp = p;
		p = p->next;
		delete temp;
	}
	L = nullptr;
}
//ͳ��������
int GetListLength(const link& L)
{
	int length = 0;
	link p = L->next;
	while (p != nullptr)
	{
		length++;
		p = p->next;
	}
	return length;
}
//ȡ�����е�i��Ԫ�ص�ֵ
datatype Getelem(const link& L, int i)
{
	link p = L->next;  // �ӵ�һ��ʵ�ʽڵ㿪ʼ
	int pos = 1;  // ��ǰ������λ��
	while (p != nullptr && pos < i)
	{
		p = p->next;  // �ƶ�����һ���ڵ�
		pos++;  // ���ӱ�����λ��
	}
	if (p == nullptr || pos > i)  // û���ҵ��� i ���ڵ�
	{
		cerr << "The element does not exist." << endl;
		return false;
	}
	datatype e = p->data;  // ��ȡ�� i ���ڵ��ֵ
	return e;
}
//��ֵ��������
link FindNode(const link& L, const datatype& value)
{
	Lnode* p = L->next;
	while (p != nullptr)
	{
		if (p->data == value)		
			return p;
		p = p->next;
	}
	return 0;  // δ�ҵ�Ŀ��ֵ��Ӧ�Ľڵ�
}
//�������в���Ԫ��
bool InsertList(link& L, int i, datatype value)
{
	if (i < 1)
	{
		cerr << "Invalid position" << endl;
		return false;
	}
	//�����ڵ�
	link p = new Lnode;
	p->data = value;
	//p->next = nullptr;
	link q = L;
	int count = 0;
	while (q!=nullptr && count < i - 1)
	{
		q = q->next;
		count++;
	}
	p->next = q->next;
	q->next = p;
	return true;
}
//ɾ�������ĳ�����
bool DeleteNode(link& L, datatype value)
{
	link p = L->next;
	link r = L;
	while (p != nullptr)
	{
		if (p->data == value)
		{
			r->next = p->next;
			delete p;
			return true;
		}
		r = p;
		p = p->next;
	}
	return false;   //δ�ҵ�ƥ��ڵ�
}
//��������
void ReverseList(link& L) 
{
	Lnode* prev = nullptr;      // ǰһ���ڵ�ָ��
	Lnode* current = L->next; // ��ǰ�ڵ�ָ��
	Lnode* next = nullptr;      // ��һ���ڵ�ָ��

	while (current != nullptr) 
	{
		next = current->next;    // �ȱ�����һ���ڵ�
		current->next = prev;    // ��ǰ�ڵ�ָ��ǰһ���ڵ㣬���ָ�뷴ת
		prev = current;          // ǰһ���ڵ�ָ������ƶ�
		current = next;          // ��ǰ�ڵ�ָ������ƶ�
	}
	L->next = prev;         // ����ͷ�ڵ�� next ָ�룬ָ��ԭ��������һ���ڵ㣨���ú�ĵ�һ���ڵ㣩
}
//������������ĺϲ�
void MergeList(link& La, link& Lb, link& Lc)
{
	Lnode* pa = La->next;
	Lnode* pb = Lb->next;
	//Lc = La;
	Lnode* pc = La;
	while (pa && pb)
	{
		if (pa->data <= pb->data) //β�巨������Ԫ��
		{
			//pc��ָ����ָ��СԪ�صĵ�ַ
			pc->next = pa;
			//�ƶ�pcָ�룬ʹ��pc��Զ��ָ���������Lc�����һ��Ԫ��
			pc = pc->next;
			//pa��Ԫ��ʹ�ù���Ҫ����ƶ�pa
			pa = pa->next;
		}
		else
		{
			//pc��ָ����ָ��СԪ�صĵ�ַ
			pc->next = pb;
			//�ƶ�pcָ�룬ʹ��pc��Զ��ָ���������Lc�����һ��Ԫ��
			pc = pc->next;
			//pb��Ԫ��ʹ�ù���Ҫ����ƶ�pa
			pb = pb->next;
		}
	}
	//�����whileѭ��ִ����Ϻ󣬽ϳ�������������һ��Ԫ�أ����Ԫ�ص���ʼ��ַ����pa����pb
	pc->next = (pa ? pa : pb);
	//����ϲ���ϣ��ͷ�Lb��ͷ���
	delete Lb;
}

//����ı���
void TraverseList(link L) 
{
	link p = L->next;
	while (p != nullptr) 
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
	link A;
	InitList(A);
	CreatListHead(A, 5);
	//InsertList(A, 4, 8);
	ReverseList(A);
	TraverseList(A);
	cout << endl;
	cout << A->next->data<<endl;
	if (A!=nullptr) cout << "empty" << endl;
	int a = GetListLength(A);
	cout << a << endl;
	int e = Getelem(A, 3);
	cout << e << endl;
	link m=FindNode(A, 4);
	cout << m << endl;
}
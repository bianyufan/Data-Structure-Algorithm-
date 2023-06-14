#include <iostream>
using namespace std;
#define maxsize 100
struct node
{
    int key;
};
struct Table
{
	node data[maxsize]; //�ռ�
	int len;         //��
};
//˳������
int SqSearch(Table& S, int e)
{
    //��һ����ʩ���ڱ�
    S.data[0].key = e;
    //�ڶ�����˳��Ƚϲ���
    int i;
    for (i = S.len; S.data[i].key != e; --i)
    {
        ; //�ղ���
    }
    return i;
    //ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��ASL=(n+1)/2
}
//���ֲ���
int Search_bin(Table& S, int e)
{
    int low = 1, high = S.len;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (e == S.data[mid].key) //e��ֵ�͵����м�λ�õ�ֵ
            return mid;
        if (e < S.data[mid].key) //e��ֵλ��С�벿��
            high = mid - 1;
        if (e > S.data[mid].key) //e��ֵλ�ڴ�벿��
            low = mid + 1;
    }
    return -1;
}
//�ֿ����

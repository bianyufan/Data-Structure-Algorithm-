#include <iostream>
using namespace std;
#define maxsize 100
struct node
{
    int key;
};
struct Table
{
	node data[maxsize]; //空间
	int len;         //表长
};
//顺序表查找
int SqSearch(Table& S, int e)
{
    //第一步：施加哨兵
    S.data[0].key = e;
    //第二步：顺序比较查找
    int i;
    for (i = S.len; S.data[i].key != e; --i)
    {
        ; //空操作
    }
    return i;
    //时间复杂度O(n)、空间复杂度O(1)，ASL=(n+1)/2
}
//二分查找
int Search_bin(Table& S, int e)
{
    int low = 1, high = S.len;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (e == S.data[mid].key) //e的值就等于中间位置的值
            return mid;
        if (e < S.data[mid].key) //e的值位于小半部分
            high = mid - 1;
        if (e > S.data[mid].key) //e的值位于大半部分
            low = mid + 1;
    }
    return -1;
}
//分块查找

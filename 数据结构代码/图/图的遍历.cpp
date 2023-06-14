#include <iostream>
using namespace std;
#define MAXSIZE 100
struct AMGraph
{
    //ͼ�Ķ�������
    char vexs[MAXSIZE];
    //ͼ���ڽӾ���
    int arcs[MAXSIZE][MAXSIZE];
    //ͼ���ܶ��������ܱ���
    int vexnum, arcnum;
};
int visited[MAXSIZE] = { 0 };
//�ڽӾ���DFS
void DFS(AMGraph& G, int v)
{
    cout << G.vexs[v] << endl;
    visited[v] = 1;
    for (int i = 0; i < G.vexnum; i++)
    {
        if ((G.arcs[v][i] != 0) && visited[i] == 0)
            DFS(G, i);
    }
}
//�ڽӾ���BFS
void BFS(AMGraph& G)
{
    for (int v = 0; v < G.vexnum; ++v)
    {
        for (int w = 0; w < G.vexnum; ++w)
        {
            if ((G.arcs[v][w] != 0) && visited[w] == 0)
            {
                cout << G.vexs[w];
                visited[w] = 1;
            }
        }
    }
    //�㷨ʱ�临�Ӷ�O(n^2)
}

#include <iostream>
using namespace std;
#define MAXSIZE 100
struct AMGraph
{
    //图的顶点向量
    char vexs[MAXSIZE];
    //图的邻接矩阵
    int arcs[MAXSIZE][MAXSIZE];
    //图的总顶点数和总边数
    int vexnum, arcnum;
};
int visited[MAXSIZE] = { 0 };
//邻接矩阵DFS
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
//邻接矩阵BFS
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
    //算法时间复杂度O(n^2)
}

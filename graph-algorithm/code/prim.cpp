#include "../../tools.cpp"
#define MAXWEIGHT INT_MAX
#define edge Edge<int>

// 邻接矩阵G表示图
void Prim(vector<vector<int>> G)
{
    int n = G.size();                      // 图的顶点数
    int s = 0;                             // 从顶点s开始构造最小生成树
    vector<bool> visited(G.size(), false); // 标记节点是否被访问
    visited[s] = true;
    priority_queue<edge, vector<edge>, greater<edge>> pq; // 小顶堆
    for (int i = 0; i < G[s].size(); i++)                 // 与顶点s相邻的边入队
    {
        if (G[s][i] < MAXWEIGHT)
            pq.push(edge(s, i, G[s][i]));
    }
    int sum = 0;
    while (!pq.empty())
    {
        edge p = pq.top(); // 取出最小边
        pq.pop();
        if (visited[p.b])
            continue;
        // 新来的顶点p.b
        visited[p.b] = true;
        sum += p.weight;
        cout << p.a << "-" << p.b << " ";
        for (int i = 0; i < n; i++) // 与顶点p.b相邻的边入队
        {
            if (G[p.b][i] < MAXWEIGHT)
                pq.push(edge(p.b, i, G[p.b][i]));
        }
    }
    cout << endl;
    cout << "sum: " << sum << endl;
}

int main()
{
    vector<vector<int>> G = {
        {0, 10, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, 11, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT},
        {10, 0, 18, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, 16, MAXWEIGHT, 12},
        {MAXWEIGHT, MAXWEIGHT, 0, 22, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, 8},
        {MAXWEIGHT, MAXWEIGHT, 22, 0, 20, MAXWEIGHT, MAXWEIGHT, 16, 21},
        {MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, 20, 0, 26, MAXWEIGHT, 7, MAXWEIGHT},
        {11, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, 26, 0, 17, MAXWEIGHT, MAXWEIGHT},
        {MAXWEIGHT, 16, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, 17, 0, 19, MAXWEIGHT},
        {MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, 16, 7, MAXWEIGHT, 19, 0, MAXWEIGHT},
        {MAXWEIGHT, 12, 8, 21, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, 0}};
    // ArrayUtils<int>::print2dArray(G);
    Prim(G);
    return 0;
}
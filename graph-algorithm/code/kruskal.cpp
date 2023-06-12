#include "../../tools.cpp"
#define edge Edge<int>
#define MAXWEIGHT INT_MAX

// Kruskal算法求解最小生成树问题
void Kruskal(vector<vector<int>> G)
{
    int n = G.size();                                     // 顶点数
    UnionFind uf(n);                                      // 并查集
    priority_queue<edge, vector<edge>, greater<edge>> pq; // 小顶堆
    // 将所有边入队
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (G[i][j] < MAXWEIGHT)
                pq.push(edge(i, j, G[i][j]));
        }
    }
    // kruskal算法
    int sum = 0;
    while (!pq.empty())
    {
        edge e = pq.top();
        pq.pop();
        if (uf.find(e.a) == uf.find(e.b)) // 如果两个顶点已经连通，说明加入这条边会形成环，跳过
            continue;
        uf.unionElements(e.a, e.b);
        sum += e.weight;
        cout << e.a << "-" << e.b << " ";
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
    Kruskal(G);
    return 0;
}
#include "../../tools.cpp"
#define P pair<int, int> // first：最短路径长度，second：顶点编号
#define MAXWEIGHT INT_MAX

// Bellman-Ford算法求解单源最短路径问题，输出以s为起点到各顶点的最短路径长度
void BellmanFord(vector<vector<int>> G, int s)
{
    int n = G.size();
    vector<int> dist(n, MAXWEIGHT); // 存储最短路径长度
    dist[s] = 0;
    bool flag = true;                       // 标记本轮松弛操作是否有更新
    for (int i = 0; i < n - 1 && flag; i++) // 最多n-1轮松弛操作
    {
        flag = false;               // 标记本轮松弛操作是否有更新
        for (int u = 0; u < n; u++) // 对每条边进行松弛操作
        {
            for (int v = 0; v < n; v++)
            {
                if (G[u][v] < MAXWEIGHT && dist[v] > dist[u] + G[u][v])
                {
                    dist[v] = dist[u] + G[u][v];
                    flag = true;
                }
            }
        }
    }
    ArrayUtils<int>::printArray(dist);
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
    BellmanFord(G, 0);
    return 0;
}
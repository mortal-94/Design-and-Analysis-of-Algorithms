#include "../../tools.cpp"
#define P pair<int, int> // first：最短路径长度，second：顶点编号
#define MAXWEIGHT INT_MAX

// Dijkstra算法求解单源最短路径问题，输出以s为起点到各顶点的最短路径长度
void Dijkstra(vector<vector<int>> G, int s)
{
    int n = G.size();
    vector<int> dist(n, MAXWEIGHT); // 存储最短路径长度
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> pq; // 小顶堆
    pq.push(P(dist[s], s));                      // 起点s入队
    while (!pq.empty())
    {
        P p = pq.top(); // dist最小的顶点
        pq.pop();
        int v = p.second;      // 顶点编号
        if (dist[v] < p.first) // 顶点v已经更新过dist
            continue;
        for (int i = 0; i < n; i++) // 更新dist
        {
            if (G[v][i] < MAXWEIGHT && dist[i] > dist[v] + G[v][i])
            {
                dist[i] = dist[v] + G[v][i];
                pq.push(P(dist[i], i));
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
    Dijkstra(G, 0);
    return 0;
}
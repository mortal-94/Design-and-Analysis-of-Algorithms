#include "../../tools.cpp"

// bfs判断是否存在增广路径，记录前缀
bool bfs(vector<vector<int>> rG, int s, int t, vector<int> &pre)
{
    int n = rG.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && rG[u][v] > 0)
            {
                q.push(v);
                visited[v] = true;
                pre[v] = u;
                if (v == t)
                    return true;
            }
        }
    }
    return false;
}

// Ford-Fulkerson算法求解最大流问题
// 输入：邻接矩阵G，源点s，汇点t；打印：最大流
void FordFulkerson(vector<vector<int>> G, int s, int t)
{
    int n = G.size();
    vector<vector<int>> rG(G); // 残余网络，初始化为G

    vector<int> pre(n, -1); // 前缀
    int max_flow = 0;
    while (bfs(rG, s, t, pre)) // 存在增广路径
    {
        int min_flow = INT_MAX;
        for (int v = t; v != s; v = pre[v]) // 找到增广路径上的最小流量
        {
            int u = pre[v];
            min_flow = min(min_flow, rG[u][v]);
        }
        for (int v = t; v != s; v = pre[v]) // 更新残余网络
        {
            int u = pre[v];
            rG[u][v] -= min_flow;
            rG[v][u] += min_flow;
        }
        max_flow += min_flow;
    }
    cout << "最大流：" << max_flow << endl;
}

int main()
{
    // 邻接矩阵G，没有边的权重为0，有边的权重为正整数
    vector<vector<int>> G = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};
    FordFulkerson(G, 0, 5);
    return 0;
}
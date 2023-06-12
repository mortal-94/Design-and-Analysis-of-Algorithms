#include "../../tools.cpp"

// 匈牙利算法求解二分图最大匹配问题

// 匹配顶点u
bool match(vector<vector<int>> G, int u, vector<int> &matched, vector<bool> &visited)
{
    int n = G.size();
    for (int v = 0; v < n; v++)
    {
        if (G[u][v] && !visited[v])
        {
            visited[v] = true;
            if (matched[v] == -1 || match(G, matched[v], matched, visited))
            {
                matched[v] = u;
                matched[u] = v;
                return true;
            }
        }
    }
    return false;
}

// 输入：邻接矩阵G；打印：最大匹配数
void hungarian(vector<vector<int>> G)
{
    int n = G.size();
    vector<int> matched(n, -1); // 匹配顶点
    int max_match = 0;
    for (int u = 0; u < n; u++) // 这里遍历所有节点，下面就要判断matched[u] < 0 才进行匹配
    {
        vector<bool> visited(n, false);
        if (matched[u] < 0 && match(G, u, matched, visited))
            max_match++;
    }
    vector<bool> visited(n, false); // 左侧顶点
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && !visited[matched[i]])
        {
            visited[i] = true;
            visited[matched[i]] = true;
            cout << i << " - " << matched[i] << endl;
        }
    }

    cout << "最大匹配数：" << max_match << endl;
}

int main()
{
    // 邻接矩阵G表示一个二部图，没有边的权重为0，有边的权重为1
    vector<vector<int>> G = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0}};

    hungarian(G);
    return 0;
}
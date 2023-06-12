#include "../../tools.cpp"
#define INF INT_MAX

// Floyd算法求解最短路径问题
// 输入：邻接矩阵G；打印：各顶点间最短路径长度
void Floyd(vector<vector<int>> G)
{
    int n = G.size();
    vector<vector<int>> D(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) // 初始化
        {
            D[i][j] = G[i][j];
        }
    int k, i, j;
    for (k = 0; k < n; k++) // 依次考虑顶点k
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) // 顶点i到顶点j的最短路径
                if (D[i][k] < INF && D[k][j] < INF && D[i][k] + D[k][j] < D[i][j]) // 
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
    cout << "各顶点间最短路径长度：" << endl;
    ArrayUtils<int>::print2dArray(D);
}

int main()
{
    vector<vector<int>> G = {
        {0, 1, 5, INF, INF, INF, INF, INF, INF},
        {1, 0, 3, 7, 5, INF, INF, INF, INF},
        {5, 3, 0, INF, 1, 7, INF, INF, INF},
        {INF, 7, INF, 0, 2, INF, 3, INF, INF},
        {INF, 5, 1, 2, 0, 3, 6, 9, INF},
        {INF, INF, 7, INF, 3, 0, INF, 5, INF},
        {INF, INF, INF, 3, 6, INF, 0, 2, 7},
        {INF, INF, INF, INF, 9, 5, 2, 0, 4},
        {INF, INF, INF, INF, INF, INF, 7, 4, 0}};
    Floyd(G);
    return 0;
}
#include "../../tools.cpp"

void printMatChain(vector<vector<int>> &Rec, int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        printMatChain(Rec, i, Rec[i][j]);
        printMatChain(Rec, Rec[i][j] + 1, j);
        cout << ")";
    }
}

// p：矩阵链的维度数组，例如：A1是10*100的矩阵，A2是100*5的矩阵，A3是5*50的矩阵，那么p={10,100,5,50}
// 输出最优的矩阵链乘法方案，以及最优乘法次数
void MatChainMultiply(vector<int> p)
{
    int n = p.size() - 1;                                         // 矩阵个数
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT32_MAX)); // dp[i][j]表示从Ai到Aj的最优乘法次数，下标从1开始
    vector<vector<int>> Rec(n + 1, vector<int>(n + 1, 0));        // Rec[i][j]表示从Ai到Aj的最优分割位置，下标从1开始
    // 初始化
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    // main loop
    for (int len = 2; len <= n; len++) // len表示矩阵链的长度
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    Rec[i][j] = k;
                }
            }
        }
    }
    cout << "min cost: " << dp[1][n] << endl;
    cout << "plan: ";
    printMatChain(Rec, 1, n);
}

int main()
{
    vector<int> p = {2, 3, 7, 9, 5, 2, 4};
    ArrayUtils<int>::printArray(p);
    for (int i = 1; i < p.size(); i++)
        cout << "A" << i << ": " << p[i - 1] << "*" << p[i] << endl;

    MatChainMultiply(p);
    return 0;
}
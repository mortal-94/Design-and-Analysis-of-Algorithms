#include "../../tools.cpp"

// n: 商品数量，p: 商品价值，v: 商品体积，C: 背包容量，Rec: 记录商品是否被选中
int Knapsack(int n, vector<int> p, vector<int> v, int C)
{
    // dp[i][j]表示前i且包括i的商品中选择，放入容量为j的背包中的最大价值
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));  // 初始化为0
    vector<vector<int>> Rec(n + 1, vector<int>(C + 1, 0)); // Rec[i][j]表示第i个商品是否被选中
    // main loop
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (v[i] <= j && dp[i - 1][j - v[i]] + p[i] > dp[i - 1][j]) // 选择第i个商品
            {
                dp[i][j] = dp[i - 1][j - v[i]] + p[i];
                Rec[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                Rec[i][j] = 0;
            }
        }
    }
    cout << "最大价值: " << dp[n][C] << endl; // TODO 检验答案的正确性
    cout << "选中的商品: ";
    for (int i = n; i >= 1; i--)
    {
        if (Rec[i][C] == 1)
        {
            cout << i << " ";
            C -= v[i];
        }
    }
    cout << endl;
    return dp[n][C];
}
int main()
{
    int n = 5, C = 15;
    cout << "背包容量: " << C << endl;
    vector<int> p = ArrayUtils<int>::generateRandomArray(n, 1, 10);
    sleep(1); // 为了让随机数不一样
    vector<int> v = ArrayUtils<int>::generateRandomArray(n, 1, 10);
    cout << "商品价值: ";
    ArrayUtils<int>::printArray(p);
    cout << "商品体积: ";
    ArrayUtils<int>::printArray(v);
    p.insert(p.begin(), -1); // 为了方便，将p[1, n]和v[1, n]对应
    v.insert(v.begin(), -1);
    int maxValue = Knapsack(n, p, v, C);
    return 0;
}
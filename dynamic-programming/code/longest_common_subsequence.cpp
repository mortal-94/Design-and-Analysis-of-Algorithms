#include "../../tools.cpp"

// 求X和Y的最长公共子序列
vector<int> LongestComSubseq(vector<int> X, vector<int> Y)
{
    int n = X.size(), m = Y.size(); // n: X的个数，m: Y的个数
    X.insert(X.begin(), 0);         // 为了方便，讲X和Y的下标从1开始
    Y.insert(Y.begin(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));  // dp[i][j]表示X[1...i]和Y[1...j]的最长公共子序列的长度
    vector<vector<int>> Rec(n + 1, vector<int>(m + 1, 0)); // Rec[i][j]记录着dp表的构造过程
    // main loop
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i] == Y[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                Rec[i][j] = 1; // 左上
            }
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                Rec[i][j] = 2; // 上
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                Rec[i][j] = 3; // 左
            }
        }
    }
    // 输出最长公共子序列
    vector<int> res;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (Rec[i][j] == 1) // 左上
        {
            res.push_back(X[i]);    // 只有在左上的时候才会添加元素
            i--;
            j--;
        }
        else if (Rec[i][j] == 2) // 上
        {
            i--;
        }
        else // 左
        {
            j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> X = ArrayUtils<int>::generateRandomArray(10, 1, 10);
    sleep(1); // 保证随机数不同
    vector<int> Y = ArrayUtils<int>::generateRandomArray(10, 1, 10);
    cout << "X: ";
    ArrayUtils<int>::printArray(X);
    cout << "Y: ";  
    ArrayUtils<int>::printArray(Y);
    vector<int> res = LongestComSubseq(X, Y);
    cout << "最长公共子序列: ";
    ArrayUtils<int>::printArray(res);
    return 0;
}
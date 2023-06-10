#include "../../tools.cpp"

// 求X和Y的最长公共子串
vector<int> LongestComSubstr(vector<int> X, vector<int> Y)
{
    int n = X.size(), m = Y.size(); // n: X的个数，m: Y的个数
    X.insert(X.begin(), 0);         // 为了方便，讲X和Y的下标从1开始
    Y.insert(Y.begin(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // dp[i][j]表示以X[i]和Y[j]结尾的最长公共子串的长度
    int maxLen = 0, end = 0;                              // maxLen记录最长公共子串的长度，maxEnd记录最长公共子串的结束位置
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i] == Y[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                    end = i;
                }
            }
        }
    }
    cout << "X[" << end - maxLen + 1 << "..." << end << "]" << endl;
    // 输出最长公共子串
    vector<int> res(X.begin() + end - maxLen + 1, X.begin() + end + 1);
    return res;
}

int main()
{
    vector<int> X = ArrayUtils<int>::generateRandomArray(15, 1, 5);
    sleep(1); // 保证随机数不同
    vector<int> Y = ArrayUtils<int>::generateRandomArray(15, 1, 5);
    cout << "X: ";
    ArrayUtils<int>::printArray(X);
    cout << "Y: ";
    ArrayUtils<int>::printArray(Y);
    vector<int> res = LongestComSubstr(X, Y);
    cout << "Longest common substring: ";
    ArrayUtils<int>::printArray(res);
    return 0;
}
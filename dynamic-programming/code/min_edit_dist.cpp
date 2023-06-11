#include "../../tools.cpp"

// 根据记录反推编辑过程
void printMED(vector<vector<int>> &Rec, string s, string t, int i, int j)
{
    if (i == 0 && j == 0)
        return;
    if (Rec[i][j] == 3)
    {
        printMED(Rec, s, t, i - 1, j - 1);
        if (s[i] != t[j])
            cout << "replace " << s[i] << " with " << t[j] << endl;
    }
    else if (Rec[i][j] == 2)
    {
        printMED(Rec, s, t, i, j - 1);
        cout << "insert " << t[j] << endl;
    }
    else
    {
        printMED(Rec, s, t, i - 1, j);
        cout << "delete " << s[i] << endl;
    }
}
// s→t的最小编辑距离
int MinEditDist(string s, string t)
{
    int n = s.size(), m = t.size();
    s.insert(s.begin(), ' '); // 为了方便，讲s和t的下标从1开始
    t.insert(t.begin(), ' ');
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));  // dp[i][j]表示s[1...i]→t[1...j]的最小编辑距离
    vector<vector<int>> Rec(n + 1, vector<int>(m + 1, 0)); // Rec[i][j]记录dp[i][j]的状态转移来源
    // 初始化
    for (int i = 0; i <= n; i++) // dp[i][0]表示s变成空串的最小编辑距离，即删除i个字符
    {
        dp[i][0] = i;
        Rec[i][0] = 1; // 1表示dp[i][0]由dp[i-1][0]转移而来，即删除一个字符
    }
    for (int j = 0; j <= m; j++) // dp[0][j]表示空串变成t的最小编辑距离，即插入j个字符
    {
        dp[0][j] = j;
        Rec[0][j] = 2; // 2表示dp[0][j]由dp[0][j-1]转移而来，即插入一个字符
    }
    // main loop
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) // dp[i][j]由dp[i-1][j]、dp[i][j-1]、dp[i-1][j-1]转移而来
        {
            int replace = dp[i - 1][j - 1] + (s[i] == t[j] ? 0 : 1);
            int insert = dp[i][j - 1] + 1;
            int del = dp[i - 1][j] + 1;
            int minDist = min(replace, min(insert, del));
            dp[i][j] = minDist;
            if (minDist == replace)
                Rec[i][j] = 3; // 3表示dp[i][j]由dp[i-1][j-1]转移而来
            else if (minDist == insert)
                Rec[i][j] = 2; // 2表示dp[i][j]由dp[i][j-1]转移而来
            else
                Rec[i][j] = 1; // 1表示dp[i][j]由dp[i-1][j]转移而来
        }
    }
    // 输出最优解
    printMED(Rec, s, t, n, m);

    return dp[n][m];
}

int main()
{
    vector<char> ss = ArrayUtils<char>::generateRandomArray(7, 'a', 'e');
    sleep(1);
    vector<char> tt = ArrayUtils<char>::generateRandomArray(6, 'a', 'e');
    string s(ss.begin(), ss.end());
    string t(tt.begin(), tt.end());
    cout << "s: " << s << endl;
    cout << "t: " << t << endl;
    int res = MinEditDist(s, t);
    cout << "MinEditDist: " << res << endl;
}
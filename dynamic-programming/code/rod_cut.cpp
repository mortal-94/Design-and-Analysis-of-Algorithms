#include "../../tools.cpp"

// p[i]表示长度为i的钢条的价格，输出最优切割方案
void RodCut(vector<int> p)
{
    int n = p.size();
    p.insert(p.begin(), 0);    // 为了方便，p的下标从1开始
    vector<int> dp(n + 1, 0);  // dp[i]表示长度为i的钢条的最大收益
    vector<int> Rec(n + 1, 0); //
    dp[0] = 0;
    // main loop
    for (int i = 1; i <= n; i++)
    {
        int maxProfit = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            int profit = p[j] + dp[i - j];
            if (profit > maxProfit)
            {
                maxProfit = profit;
                Rec[i] = j;
            }
        }
        dp[i] = maxProfit;
    }
    cout << "max profit: " << dp[n] << endl;
    cout << "cut plan: ";
    while (n > 0)
    {
        cout << Rec[n] << "m:" << p[Rec[n]] << "$ ";
        n -= Rec[n];
    }
    cout << endl;
}

int main()
{
    vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20, 24, 24};
    ArrayUtils<int>::printArray(p);
    RodCut(p);
    return 0;
}
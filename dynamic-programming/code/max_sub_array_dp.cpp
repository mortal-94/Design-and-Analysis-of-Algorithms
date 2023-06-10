#include "../../tools.cpp"

// 求A的最大子数组和
int MaxSubArray(vector<int> A)
{
    // dp[i]表示以A[i]结尾的最大子数组和
    vector<int> dp(A.size(), 0);
    vector<int> Rec(A.size(), 0);
    dp[0] = A[0];
    Rec[0] = 0; // Rec[i]表示以A[i]结尾的最大子数组和的起始位置
    for (int i = 1; i < A.size(); i++)
    {
        if (dp[i - 1] > 0)
        {
            dp[i] = dp[i - 1] + A[i];
            Rec[i] = Rec[i - 1];
        }
        else
        {
            dp[i] = A[i];
            Rec[i] = i;
        }
    }
    int maxSum = INT_MIN;
    int l, r;
    for (int i = 0; i < A.size(); i++)
    {
        if (dp[i] > maxSum)
        {
            maxSum = dp[i];
            l = Rec[i];
            r = i;
        }
    }
    cout << "[" << l << ", " << r << "]" << endl;
    return maxSum;
}

int main()
{
    int size = 5, minValue = -100, maxValue = 100;
    vector<int> arr = ArrayUtils<int>::generateRandomArray(size, minValue, maxValue);
    cout << "Array: ";
    ArrayUtils<int>::printArray(arr, size);
    int maxSum = MaxSubArray(arr);
    cout << "Max sub array sum: " << maxSum << endl; // TODO 检验答案的正确性
    return 0;
}
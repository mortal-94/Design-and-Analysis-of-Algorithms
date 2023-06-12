#include "../../tools.cpp"

// 回溯法求解n皇后问题

// 排列树
bool Place(int k, vector<int> &x)
{
    for (int i = 1; i < k; i++)
        if (abs(k - i) == abs(x[i] - x[k])) // 同一对角线
            return false;
    return true;
}
void backtrack(int t, int n, vector<int> &x, int &sum)
{
    if (t > n)
    {
        sum++;
        ArrayUtils<int>::printArray(x, 1, n + 1);
    }
    else
    {
        for (int i = t; i <= n; i++)    
        {
            swap(x[t], x[i]); 
            if (Place(t, x))
                backtrack(t + 1, n, x, sum);
            swap(x[t], x[i]);
        }
    }
}

// 子集树
bool Place0(int k, vector<int> &x)
{
    for (int i = 1; i < k; i++)
        if (abs(k - i) == abs(x[i] - x[k]) || x[i] == x[k]) // 同一对角线或同一列
            return false;
    return true;
}
void backtrack0(int t, int n, vector<int> &x, int &sum)
{
    if (t > n)
    {
        sum++;
        ArrayUtils<int>::printArray(x, 1, n + 1);
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            x[t] = i; // 第t行的皇后放在第i列
            if (Place0(t, x))
                backtrack0(t + 1, n, x, sum);
        }
    }
}

int main()
{
    int n = 4;
    vector<int> x(n + 1);            // x[0]不用
    iota(x.begin() + 1, x.end(), 1); // 排列树要解要初始化为1~n
    int sum = 0;
    backtrack(1, n, x, sum);
    cout << sum << endl;
    cout << "--------------------------" << endl;
    vector<int> x0(n + 1);
    sum = 0;
    backtrack0(1, n, x0, sum);
    cout << sum << endl;
    return 0;
}
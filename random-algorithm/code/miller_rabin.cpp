#include "../../tools.cpp"
/*
Miller-Rabin 素数测试算法
参考：https://blog.csdn.net/ECNU_LZJ/article/details/72675595
*/

// 快速幂，计算 a^b % mod
long long qpow(long long a, long long b, long long mod)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Miller-Rabin素性测试
bool Miller_Rabin(long long n, int test_time = 10)
{
    if (n == 2)
        return true;
    if (n < 2 || !(n & 1)) // 0, 1, 偶数
        return false;
    long long a, x, u = n - 1;
    int t = 0;
    while (!(u & 1)) // 把n-1分解成u*2^t
    {
        u >>= 1;
        t++;
    }
    int i;
    while (test_time--) // 进行test_time次测试
    {
        a = rand() % (n - 1) + 1; // 随机选取测试基数a∈[0, n-1]
        x = qpow(a, u, n);        // x = a^u % n
        if (x == 1 || x == n - 1)
            continue;
        for (i = 0; i < t; i++) // 分别计算 a^2u, a^4u, ..., a^
        {
            x = x * x % n;
            if (x == n - 1) // 如果中间有一个等于n-1，那么n通过测试
                break;
        }
        if (i >= t) // 如果中间没有一个等于n-1，那么n不是素数
            return false;
    }
    return true;
}

int main()
{
    long long n;
    cin >> n;
    if (Miller_Rabin(n)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
class ArrayUtils
{
public:
    // 生成长度为n，范围在[low, high]之间的随机数组
    static T *generateRandomArray(int n, T low, T high)
    {
        T *arr = new T[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % (high - low + 1) + low;
        }
        return arr;
    }

    // 打印数组arr的前n个元素
    static void printArray(T *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
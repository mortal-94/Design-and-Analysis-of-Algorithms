#include <iostream>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <time.h>
#include <vector>
#include <unistd.h>
#include <numeric>
using namespace std;

template <typename T>
class ArrayUtils
{
public:
    // 生成长度为n，范围在[low, high]之间的随机数组
    static vector<T> generateRandomArray(int n, T low, T high)
    {
        vector<T> arr(n);
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % (high - low + 1) + low;
        }
        return arr;
    }

    // 打印数组
    static void printArray(vector<T> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // 打印前n个元素
    static void printArray(vector<T> arr, int n)
    {
        assert(n <= arr.size());
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // 打印二维数组
    static void print2dArray(vector<vector<T>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            printArray(arr[i]);
        }
    }

    // 判断数组是否有序
    static bool isSorted(vector<T> arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] > arr[i])
                return false;
        }
        return true;
    }    
};
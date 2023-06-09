#include <iostream>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include "../../tools.cpp"
using namespace std;

// 对数组A的片段A[left, right]进行快速排序
int *QucikSort(int *A, int left, int right)
{
    if (left < right)
    {
        // 随机选取一个数作为基准数
        int pivot = A[left + rand() % (right - left + 1)];
        int i = left, j = right;
        while (i <= j)
        {
            while (A[i] < pivot) // 左边找大的
                i++;
            while (A[j] > pivot) // 右边找小的
                j--;
            if (i <= j)
            {
                swap(A[i], A[j]);
                i++;
                j--;
            }
        }
        QucikSort(A, left, j);
        QucikSort(A, i, right);
    }
    return A;
}

int main()
{
    int size = 15, minValue = -100, maxValue = 100;
    int *arr = ArrayUtils<int>::generateRandomArray(size, minValue, maxValue);
    int *stdArr = new int[size];
    memcpy(stdArr, arr, size * sizeof(int));
    cout << "Before sort: ";
    ArrayUtils<int>::printArray(arr, size);
    sort(stdArr, stdArr + size);
    assert(ArrayUtils<int>::isEqual(QucikSort(arr, 0, size - 1), stdArr, size));
    QucikSort(arr, 0, size - 1);
    cout << "After sort: ";
    ArrayUtils<int>::printArray(arr, size);
    delete[] arr, stdArr;
    return 0;
}
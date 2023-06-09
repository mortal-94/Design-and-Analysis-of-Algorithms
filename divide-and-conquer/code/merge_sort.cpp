#include <iostream>
#include <string.h>
#include "../../tools.cpp"
using namespace std;

// 把有序数组片段A[left, mid]和A[mid+1, right]合并成一个整个有序数组片段A[left, right]
void Merge(int *A, int left, int mid, int right)
{
    int n1 = mid - left + 1; // 左边数组的长度
    int n2 = right - mid;    // 右边数组的长度
    int *L = new int[n1];    // 左边数组
    int *R = new int[n2];    // 右边数组
    memcpy(L, A + left, n1 * sizeof(int));
    memcpy(R, A + mid + 1, n2 * sizeof(int));
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while (i < n1)
        A[k++] = L[i++];
    while (j < n2)
        A[k++] = R[j++];
    delete[] L;
    delete[] R;
}
// 对数组A[left, right]进行归并排序
int *MergeSort(int *A, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
    return A;
}

int main()
{
    int maxSize = 15, minValue = 0, maxValue = 100;
    int *arr = ArrayUtils<int>::generateRandomArray(maxSize, minValue, maxValue);
    cout << "Before sort: ";
    for (int i = 0; i < maxSize; i++)
        cout << arr[i] << " ";
    cout << endl;
    MergeSort(arr, 0, maxSize - 1);
    cout << "After sort: ";
    for (int i = 0; i < maxSize; i++)
        cout << arr[i] << " ";
    cout << endl;
    delete[] arr;
    return 0;
}

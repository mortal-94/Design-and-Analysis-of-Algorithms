#include "../../tools.cpp"

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
void MergeSort(int *A, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}

int main()
{
    int size = 15, minValue = -100, maxValue = 100;
    int *arr = ArrayUtils<int>::generateRandomArray(size, minValue, maxValue);
    int *stdArr = new int[size];
    memcpy(stdArr, arr, size * sizeof(int));
    cout << "Before sort: ";
    ArrayUtils<int>::printArray(arr, size);
    MergeSort(arr, 0, size - 1);
    sort(stdArr, stdArr + size);
    assert(ArrayUtils<int>::isEqual(arr, stdArr, size));
    cout << "After sort: ";
    ArrayUtils<int>::printArray(arr, size);
    delete[] arr, stdArr;
    return 0;
}

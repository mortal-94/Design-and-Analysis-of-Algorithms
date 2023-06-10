#include "../../tools.cpp"

// 对跨越A[left, right]中点mid的逆序对进行统计，A[left, mid]和A[mid+1, right]已经有序
int MergeCount(int *A, int left, int mid, int right)
{
    int *A1 = new int[right - left + 1];
    memcpy(A1, A + left, (right - left + 1) * sizeof(int)); // 保留A[left, mid]的副本
    int i = 0, j = mid - left + 1, k = 0, count = 0;
    while (i <= mid - left && j <= right - left)
    {
        if (A1[i] <= A1[j])
        {
            A[left + k] = A1[i];
            i++, k++;
        }
        else
        {
            A[left + k] = A1[j];
            count += mid - left - i + 1; // A1[i]和A1[j]构成逆序对，A1[i]后面的数都和A1[j]构成逆序对
            j++, k++;
        }
    }
    while (i <= mid - left)
    {
        A[left + k] = A1[i];
        i++, k++;
    }
    while (j <= right - left)
    {
        A[left + k] = A1[j];
        j++, k++;
    }
    delete[] A1;
    return count;
}

// 对数组A的片段A[left, right]统计逆序对的个数
int CountInver(int *A, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        int countLeft = CountInver(A, left, mid);
        int countRight = CountInver(A, mid + 1, right);
        int countMerge = MergeCount(A, left, mid, right);
        return countLeft + countRight + countMerge;
    }
    return 0;
}

int main()
{
    int size = 5, minValue = -100, maxValue = 100;
    int *arr = ArrayUtils<int>::generateRandomArray(size, minValue, maxValue);
    cout << "Array: ";
    ArrayUtils<int>::printArray(arr, size);
    int count = CountInver(arr, 0, size - 1); // TODO 验证结果正确性
    cout << "Inversion count: " << count << endl;
    cout << "Array: ";
    ArrayUtils<int>::printArray(arr, size);
    delete[] arr;
    return 0;
}
#include "../../tools.cpp"

int Partition(int *A, int left, int right)
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
    // 此时i=j+1
    return j;
}

// 返回数组A[left, right]中第k小的数
int OrderSlect(int *A, int left, int right, int k)
{
    int p = Partition(A, left, right);
    if (p - left + 1 == k)
    {
        return A[p];
    }
    else if (p - left + 1 > k)
    {
        return OrderSlect(A, left, p, k);
    }
    else
    {
        return OrderSlect(A, p + 1, right, k - (p - left + 1));
    }
}

int main()
{
    int size = 15, minValue = -100, maxValue = 100;
    int *arr = ArrayUtils<int>::generateRandomArray(size, minValue, maxValue);
    cout << "original array: ";
    ArrayUtils<int>::printArray(arr, size);
    int *stdArr = new int[size];
    memcpy(stdArr, arr, size * sizeof(int));
    int k = 5;
    int x = OrderSlect(arr, 0, size - 1, k);
    sort(stdArr, stdArr + size);
    cout << "sorted array: ";
    ArrayUtils<int>::printArray(stdArr, size);
    assert(x == stdArr[k - 1]);
    cout << "The " << k << "th smallest number is " << x << endl;
    return 0;
}
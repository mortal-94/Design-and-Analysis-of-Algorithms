#include "../../tools.cpp"

// 把有序数组片段A[left, mid]和A[mid+1, right]合并成一个整个有序数组片段A[left, right]
void Merge(vector<int> &A, int left, int mid, int right)
{
    vector<int> L(A.begin() + left, A.begin() + mid + 1);      // 左边数组
    vector<int> R(A.begin() + mid + 1, A.begin() + right + 1); // 右边数组
    int n1 = L.size(), n2 = R.size();
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    copy(L.begin() + i, L.begin() + n1, A.begin() + k); // 将L[i, n1]复制到A[k, right]
    copy(R.begin() + j, R.begin() + n2, A.begin() + k); // 将R[j, n2]复制到A[k, right]
}
// 对数组A[left, right]进行归并排序
void MergeSort(vector<int> &A, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}

void check()
{
    int num = 500;
    int minValue = -100, maxValue = 100;
    while (num--)
    {
        int size = rand() % 100;
        vector<int> arr = ArrayUtils<int>::generateRandomArray(size, minValue, maxValue);
        MergeSort(arr, 0, size - 1);
        assert(ArrayUtils<int>::isSorted(arr));
    }
    cout << "Passed!" << endl;
}

int main()
{
    check();
    int size = 15, minValue = -100, maxValue = 100;
    vector<int> arr = ArrayUtils<int>::generateRandomArray(size, minValue, maxValue);
    cout << "Before sort: ";
    ArrayUtils<int>::printArray(arr, size);
    MergeSort(arr, 0, size - 1);
    cout << "After sort: ";
    ArrayUtils<int>::printArray(arr, size);
    return 0;
}

#include "../../tools.cpp"

// 对跨越A[left, right]中点mid的逆序对进行统计，A[left, mid]和A[mid+1, right]已经有序
int MergeCount(vector<int> &A, int left, int mid, int right)
{
    vector<int> A1(A.begin() + left, A.begin() + right + 1); // A1 = A[left, right]
    // A1[0, right - left] = A[left, right]，即偏移量为left
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
    copy(A1.begin() + i, A1.begin() + mid - left + 1, A.begin() + left + k);   // 将A1[i, mid - left]复制到A[left + k, right]
    copy(A1.begin() + j, A1.begin() + right - left + 1, A.begin() + left + k); // 将A1[j, right - left]复制到A[left + k, right]
    return count;
}

// 对数组A的片段A[left, right]统计逆序对的个数
int CountInver(vector<int> &A, int left, int right)
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
    vector<int> arr = ArrayUtils<int>::generateRandomArray(size, minValue, maxValue);
    cout << "Array: ";
    ArrayUtils<int>::printArray(arr, size);
    int count = CountInver(arr, 0, size - 1);
    cout << "Inversion count: " << count << endl;
    cout << "Array: ";
    ArrayUtils<int>::printArray(arr, size);
    return 0;
}
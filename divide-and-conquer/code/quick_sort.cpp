#include "../../tools.cpp"

int Partition(vector<int> &A, int left, int right)
{
    // 随机选取基准元素放到A[right]做为基准元素
    srand(time(NULL));
    int pivotIdx = rand() % (right - left + 1) + left;
    swap(A[right], A[pivotIdx]);
    int i = left - 1, pivot = A[right];
    // i及i左边的元素都小于等于pivot，i右边的元素都大于pivot
    for (int j = left; j < right; j++)
    {
        if (A[j] <= pivot)
        {
            swap(A[i + 1], A[j]);
            i++;
        }
    }
    // A[right]是等于pivot的元素，所以将其放到i+1的位置，然后返回i+1
    swap(A[i + 1], A[right]);
    return i + 1;
}

// 对数组A的片段A[left, right]进行快速排序
void QucikSort(vector<int> &A, int left, int right)
{
    if (left < right)
    {
        int p = Partition(A, left, right);
        QucikSort(A, left, p - 1);
        QucikSort(A, p + 1, right);
    }
}

void check()
{
    int num = 500;
    int minValue = -100, maxValue = 100;
    for (int i = 0; i < num; i++)
    {
        int size = rand() % 100;
        vector<int> arr = ArrayUtils<int>::generateRandomArray(size, minValue, maxValue);
        QucikSort(arr, 0, size - 1);
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
    QucikSort(arr, 0, size - 1);
    cout << "After sort: ";
    ArrayUtils<int>::printArray(arr, size);
    return 0;
}
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

// 返回数组A[left, right]中第k小的数
int OrderSlect(vector<int> &A, int left, int right, int k)
{
    int p = Partition(A, left, right);
    if (p - left + 1 == k)
    {
        return A[p];
    }
    else if (p - left + 1 > k)
    {
        return OrderSlect(A, left, p - 1, k);
    }
    else
    {
        return OrderSlect(A, p + 1, right, k - (p - left + 1));
    }
}

int main()
{
    int size = 15, minValue = -100, maxValue = 100;
    vector<int> arr = ArrayUtils<int>::generateRandomArray(size, minValue, maxValue);
    cout << "original array: ";
    ArrayUtils<int>::printArray(arr);
    vector<int> stdArr(arr);
    int k = 5;
    int x = OrderSlect(arr, 0, size - 1, k);
    sort(stdArr.begin(), stdArr.end());
    cout << "sorted array: ";
    ArrayUtils<int>::printArray(stdArr);
    assert(x == stdArr[k - 1]);
    cout << "The " << k << "th smallest number is " << x << endl;
    return 0;
}
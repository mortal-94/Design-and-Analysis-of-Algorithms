#include "../../tools.cpp"

int CrossMaxSubArray(int *A, int left, int mid, int right)
{
    int leftSum = INT_MIN, rightSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= left; i--)
    {
        sum += A[i];
        leftSum = max(leftSum, sum);
    }
    sum = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += A[i];
        rightSum = max(rightSum, sum);
    }
    return leftSum + rightSum;
}
int MaxSubArray(int *A, int left, int right)
{
    if (left == right)
        return A[left];
    int mid = (left + right) / 2;
    int leftSum = MaxSubArray(A, left, mid);
    int rightSum = MaxSubArray(A, mid + 1, right);
    int crossSum = CrossMaxSubArray(A, left, mid, right);
    return max(max(leftSum, rightSum), crossSum);
}

int main()
{
    int size = 15, minValue = -100, maxValue = 100;
    int *arr = ArrayUtils<int>::generateRandomArray(size, minValue, maxValue);
    cout << "Array: ";
    ArrayUtils<int>::printArray(arr, size);
    int maxSum = MaxSubArray(arr, 0, size - 1);
    cout << "Max sub array sum: " << maxSum << endl; // TODO 检验答案的正确性
    delete[] arr;
    return 0;
}
#include <iostream>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <time.h>
#include <vector>
#include <unistd.h>
#include <numeric>
#include <queue>
using namespace std;

template <typename T>
class ArrayUtils
{
public:
    // 生成长度为n，范围在[low, high]之间的随机数组
    static vector<T> generateRandomArray(int n, T low, T high)
    {
        vector<T> arr(n);
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % (high - low + 1) + low;
        }
        return arr;
    }

    // 打印数组
    static void printArray(vector<T> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // 打印[l,r)的元素
    static void printArray(vector<T> arr, int l, int r)
    {
        assert(r - l + 1 <= arr.size());
        for (int i = l; i < r; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // 打印二维数组
    static void print2dArray(vector<vector<T>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            printArray(arr[i]);
        }
    }

    // 判断数组是否有序
    static bool isSorted(vector<T> arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] > arr[i])
                return false;
        }
        return true;
    }
};

template <typename T>
struct BNode
{
    T val;
    BNode *left;
    BNode *right;
    BNode(T x) : val(x), left(NULL), right(NULL) {}
};

// 并查集
class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank; // rank[i]表示以i为根的集合所表示的树的层数
    int count;

public:
    UnionFind(int n)
    {
        count = n;
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int p)
    {
        assert(p >= 0 && p < count);
        while (p != parent[p])
        {
            parent[p] = parent[parent[p]]; // 路径压缩
            p = parent[p];
        }
        return p;
    }

    void unionElements(int p, int q) // 按秩合并
    {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return;
        if (rank[pRoot] < rank[qRoot])
        {
            parent[pRoot] = qRoot;
        }
        else if (rank[pRoot] > rank[qRoot])
        {
            parent[qRoot] = pRoot;
        }
        else
        {
            parent[pRoot] = qRoot;
            rank[qRoot]++;
        }
    }
};

// 边结构
template <typename T>
struct Edge
{
    int a, b;
    T weight;
    Edge() {}
    Edge(int a, int b) : a(a), b(b) {}
    Edge(int a, int b, T weight) : a(a), b(b), weight(weight) {}
    bool operator<(const Edge &e) const
    {
        return weight < e.weight;
    }
};
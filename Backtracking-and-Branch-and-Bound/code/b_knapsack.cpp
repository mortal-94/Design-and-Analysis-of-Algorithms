#include "../../tools.cpp"

struct NodeVal
{
    int profit;    // 当前价值
    int weight;    // 当前重量
    double bound;  // 当前价值上界
    int level;     // 当前层数
    vector<int> x; // 当前解
    NodeVal() {}
    NodeVal(int p, int w, double b, int l, vector<int> x) : profit(p), weight(w), bound(b), level(l), x(x) {}
    bool operator<(const NodeVal &node) const
    {
        return bound < node.bound;
    }
};

// 计算上界
double bound(NodeVal node, int n, int C, vector<int> p, vector<int> w)
{
    if (node.weight >= C) // 超重，直接置零
        return 0;
    double b = node.profit;
    int j = node.level + 1;
    int totweight = node.weight;
    while (j < n && totweight + w[j] <= C)
    {
        totweight += w[j];
        b += p[j];
        j++;
    }
    if (j < n)
        b += (C - totweight) * p[j] / w[j];
    return b;
}

// 回溯法求解0-1背包问题
void dfs(vector<int> &p1, vector<int> &w1, vector<pair<double, int>> &pw, int &C, int &maxprofit, vector<int> &bestx, NodeVal u)
{
    if (u.level == p1.size() - 1) // 叶子节点
    {
        if (u.profit > maxprofit)
        {
            maxprofit = u.profit;
            bestx = u.x;
        }
    }
    else
    {
        NodeVal v;
        v.level = u.level + 1;
        // 左儿子节点
        v.weight = u.weight + w1[v.level];
        v.profit = u.profit + p1[v.level];
        v.x = u.x;
        v.x[pw[v.level].second] = 1; // 标记选择
        if (v.weight <= C && v.profit > maxprofit)
        {
            maxprofit = v.profit;
            bestx = v.x;
        }
        if (bound(v, p1.size(), C, p1, w1) > maxprofit)
            dfs(p1, w1, pw, C, maxprofit, bestx, v);
        // 右儿子节点
        v.weight = u.weight;
        v.profit = u.profit;
        v.x = u.x;
        v.x[pw[v.level].second] = 0;
        if (bound(v, p1.size(), C, p1, w1) > maxprofit)
            dfs(p1, w1, pw, C, maxprofit, bestx, v);
    }
}

// 分支界限法求解0-1背包问题
void bfs(vector<int> &p1, vector<int> &w1, int C, vector<pair<double, int>> &pw, int &n)
{
    // 广度优先搜索
    priority_queue<NodeVal> pq;                // 优先队列
    NodeVal u(0, 0, 0, -1, vector<int>(n, 0)); // 根节点
    NodeVal v;
    u.bound = bound(u, n, C, p1, w1);
    pq.push(u);
    int maxprofit = 0;
    vector<int> bextx(n, 0);
    while (!pq.empty())
    {
        u = pq.top();
        pq.pop();
        if (u.level < n - 1) // 不是叶子节点
        {
            v.level = u.level + 1;
            // 左儿子节点
            v.weight = u.weight + w1[v.level];
            v.profit = u.profit + p1[v.level];
            v.x = u.x;
            v.x[pw[v.level].second] = 1; // 标记选择
            if (v.weight <= C && v.profit > maxprofit)
            {
                maxprofit = v.profit;
                bextx = v.x;
            }
            v.bound = bound(v, n, C, p1, w1); // 计算上界，超重会置零
            if (v.bound > maxprofit)
                pq.push(v);
            // 右儿子节点
            v.weight = u.weight;
            v.profit = u.profit;
            v.x = u.x;
            v.x[pw[v.level].second] = 0;
            v.bound = bound(v, n, C, p1, w1);
            if (v.bound > maxprofit)
                pq.push(v);
        }
    }
    cout << "maxprofit: " << maxprofit << endl;
    cout << "bestx: ";
    ArrayUtils<int>::printArray(bextx);
}

// p: 物品价值，w: 物品重量，C: 背包容量
void BKnapsack(vector<int> p, vector<int> w, int C)
{
    assert(p.size() == w.size());
    int n = p.size();
    // p与w按照单位重量价值从大到小排序
    vector<pair<double, int>> pw;
    for (int i = 0; i < n; i++)
        pw.push_back(make_pair(p[i] * 1.0 / w[i], i));
    sort(pw.begin(), pw.end(), greater<pair<double, int>>());
    vector<int> p1(n), w1(w.size());
    for (int i = 0; i < n; i++)
    {
        p1[i] = p[pw[i].second];
        w1[i] = w[pw[i].second];
    }
    cout << "分支界限法求解0-1背包问题：" << endl;
    bfs(p1, w1, C, pw, n);
    cout << "回溯法求解0-1背包问题：" << endl;
    int maxprofit = 0;
    vector<int> bestx(n, 0);
    NodeVal u(0, 0, 0, -1, vector<int>(n, 0));
    dfs(p1, w1, pw, C, maxprofit, bestx, u);
    cout << "maxprofit: " << maxprofit << endl;
    cout << "bestx: ";
    ArrayUtils<int>::printArray(bestx);
}

int main()
{
    vector<int> p = {7, 5, 15, 10, 6, 18, 3};
    vector<int> w = {7, 3, 5, 2, 1, 4, 1};
    ArrayUtils<int>::printArray(p);
    ArrayUtils<int>::printArray(w);
    int C = 15;
    BKnapsack(p, w, C);
    return 0;
}
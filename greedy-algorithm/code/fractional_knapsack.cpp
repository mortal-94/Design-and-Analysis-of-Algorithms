#include "../../tools.cpp"

// p: 价格；v: 体积；C: 背包容量
void FractionalKnapsack(vector<int> p, vector<int> v, int C)
{
    vector<int> idx(p.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j)
         { return p[i] / v[i] > p[j] / v[j]; }); // 按单位体积价格降序排列
    int i = 0, sum = 0;
    while (i < idx.size() && C >= 0)
    {
        if (C >= v[idx[i]]) // 装得下
        {
            cout << "选择了" << idx[i] << "号物品" << endl; // 输出选择的物品编号
            sum += p[idx[i]];
            C -= v[idx[i]];
        }
        else // 装不下
        {
            cout << "选择了" << idx[i] << "号物品的 " << C << " 部分" << endl; // 输出选择的物品编号
            sum += p[idx[i]] * C / v[idx[i]];
            C = 0;
        }
        i++;
    }
    cout << "总价值为：" << sum << endl;
}

int main()
{
    vector<int> p = {36, 16, 45, 60, 10};
    vector<int> v = {200, 100, 300, 600, 200};
    int C = 800;
    FractionalKnapsack(p, v, C);
    return 0;
}
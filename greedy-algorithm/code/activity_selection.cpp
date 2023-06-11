#include "../../tools.cpp"

void ActivitySelection(vector<int> start, vector<int> end)
{
    assert(start.size() == end.size());
    vector<pair<int, int>> activities;
    for (int i = 0; i < start.size(); i++)
    {
        activities.push_back(make_pair(start[i], end[i]));
    }
    sort(activities.begin(), activities.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; }); // 按照结束时间排序
    int count = 1;
    int end_time = activities[0].second;
    cout << 0 << "th " << activities[0].first << " " << activities[0].second << endl;
    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].first >= end_time) // 没有冲突
        {
            cout << i << "th " << activities[i].first << " " << activities[i].second << endl;
            count++;
            end_time = activities[i].second;
        }
    }
    cout << count << endl;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    ArrayUtils<int>::printArray(start);
    ArrayUtils<int>::printArray(end);
    ActivitySelection(start, end);
    return 0;
}
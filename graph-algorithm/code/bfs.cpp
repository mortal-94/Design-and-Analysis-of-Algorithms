#include "../../tools.cpp"

// 广度优先搜索
void BFS(vector<vector<int>> graph, int start)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2, 4},
        {0, 1, 3, 4},
        {0, 2, 4},
        {1, 2, 3}};
    
    BFS(graph, 0);
    return 0;
}
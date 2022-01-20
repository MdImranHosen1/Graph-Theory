#include <bits\stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
unordered_map<int, vector<int>> adj;
vector<pair<int, int>> bridge;
void DFS(int pa, vector<int> &disc, vector<int> &low, vector<int>& parent)
{
    static int time = 0;
    disc[pa] = low[pa] = time;
    time+=1;
    for (int ch : adj[pa])
    {
        if(disc[ch]==-1)
        {
            parent[ch]=pa;
            DFS(ch,disc,low,parent);
            low[pa]=min(low[pa],low[ch]);
            if(disc[pa]<low[ch])
            {
                bridge.push_back({pa,ch});
            }

        }
        else if(ch!=parent[pa])
        {
            low[pa]=min(disc[ch],low[pa]);
        }
    }
}
void findBridges_Targan(int v)
{
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    vector<int> parent(v, -1);
    for (int i = 0; i < v; ++i)
    {
        if (disc[i] == -1)
        {
            DFS(i, disc, low, parent);
        }
    }
    cout << "Bridge are: \n";
    for (auto it : bridge)
    {
        cout << it.first << "-->" << it.second << endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    findBridges_Targan(v);
    return 0;
}
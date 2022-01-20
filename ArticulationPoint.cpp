#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define FOR(i, a, b) for (i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof a)
#define memn(a) memset(a, -1, sizeof a)

const int Inf = (int)2e9 + 5;
const ll Lnf = (ll)2e18 + 5;
const int N = 5e5 + 5;
const int NN = 1e6 + 5;
unordered_map<int, vector<int>> adj;

void DFS(int pa, vector<int> &disc, vector<int>& low, vector<int> &parent, vector<bool> &articularPoint)
{
    static int time = 0;
    disc[pa] = low[pa] = time;
    time++;
    int childen = 0;
    for (int ch : adj[pa])
    {
        if (disc[ch] == -1)
        {
            childen++;
            parent[ch] = pa;
            DFS(ch, disc, low, parent, articularPoint);
            low[pa] = min(low[pa], low[ch]);
            if (childen > 1 and parent[pa] == -1)
            {
                articularPoint[pa] = true;
            }
            if (low[ch] >= disc[pa] and parent[pa] != -1)
            {
                articularPoint[pa] = true;
            }
        }
        else if (parent[pa] != ch)
        {
            low[pa] = min(disc[ch], low[pa]);
        }
    }
}

void findArticulatoinPoint(int v)
{
    vector<int> disc(v, -1), low(v, -1), parent(v, -1);
    vector<bool> articularPoint(v, false);
    for (int i = 0; i < v; i++)
    {
        if (disc[i] == -1)
        {
            DFS(i, disc, low, parent, articularPoint);
        }
    }
    cout << "Articulation Points are::\n";
    for (int i = 0; i < v; i++)
    {
        if (articularPoint[i] == true)
        {
            cout << i << " ";
        }
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
    findArticulatoinPoint(v);
    return 0;
}

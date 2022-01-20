#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define     Yes   printf("Yes\n")
#define     No    printf("No\n")
#define     YES   printf("YES\n")
#define     NO    printf("NO\n")
#define     Noo    printf("-1\n")
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)

#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s, char c) {vector<string>v; stringstream ss(s); string x; while (getline(ss, x, c))v.emplace_back(x); return move(v);} void err(vector<string>::iterator it) {}
template<typename T, typename... Args>void err(vector<string>::iterator it, T a, Args...args) {cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " "; err(++it, args...);}

const int lim = 1048576;
const int Inf           = (int)2e9 + 5;
const ll  Lnf           = (ll)2e18 + 5;
const int N             = 5e5 + 5;
const int NN            = 1e6 + 5;


vector<int >v[N], rev[N];
std::vector<int> visit(N, -1);
stack<int>s;
int vertex, edge;

int reverse()
{
  for (int i = 0; i < vertex; ++i)
  {
    for(int j=0;j<v[i].size() ;j++)
    {
      rev[v[i][j]].push_back(i);
    }
  }
}



int dfs(int i)
{

  visit[i] = 1;
  for (int j = 0; j < v[i].size(); ++j)
  {
    if (visit[v[i][j]] == -1)
      dfs(v[i][j]);
  }
  s.push(i);
}


int dfs2(int i)
{
  cout << i << " ";
  visit[i] = 1;
  for (int j = 0; j < rev[i].size(); ++j)
  {
    if (visit[rev[i][j]] == -1)
    {
      dfs2(rev[i][j]);
    }
  }
}
void findSCC()
{
  for (int i = 0; i < vertex; ++i)
  {
    if (visit[i] == -1)
    {
      dfs(i);
    }
  }
  reverse();

  for (int i = 0; i < vertex; ++i)
  {
    visit[i] = -1;
  }
  cout << "Strongly connected component are:\n";
  while (!s.empty())
  {

    if (visit[s.top()] == -1)
    {
      dfs2(s.top());
      cout << endl;
    }
    s.pop();

  }


}


int main()
{
  cout << "Enter the number of vertex and edge\n";
  cin >> vertex >> edge;
  for (int i = 0; i < edge; ++i)
  {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
  }
  findSCC();


}



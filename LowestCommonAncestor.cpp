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
#define     sort(x)     sort(x.begin() , x.end())
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

vector<int>v[N];
//parent and child node
vector<int>histry(N);

void dfs(int child , int parent = -1)
{
	histry[child] = parent;
	for (int i : v[child])
	{
		if (i == parent)continue;
		else
			dfs(i, child);
	}
}

vector<int> path(int x)
{
	std::vector<int> a;
	while (x != -1)
	{
		a.pb(histry[x]);
		x = histry[x];
	}
	reverse(all(a));
	return a;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1, -1);

	int x, y;
	cin >> x >> y;
	// for x;
	vector<int>a=path(x);
	//for y;
	vector<int>b=path(y);


	int ans = -1;
	for (int i = 0; i < a.size() and i < b.size(); ++i)
	{
		if (a[i] == b[i])
		{
			ans = a[i];
			continue ;
		}
		else
		{
			break;
		}
	}
	cout << ans << endl;

}

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
int lvl[N];

void dfs(int child , int parent)
{
	for (int i : v[child])
	{
		if (i == parent)continue;

		lvl[i] = lvl[child] + 1;
		dfs(i, child);
	}
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

	dfs(1, 0);
	int maxlvl = 0;
	int mxlvIndex = 0;
	int mxlvIndex2 = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (lvl[i] > maxlvl)
		{
			maxlvl = lvl[i];
			mxlvIndex = i;
		}
	}
	mxlvIndex2 = mxlvIndex;

	mem(lvl);
	dfs(mxlvIndex, 0);

	for (int i = 1; i <= n; ++i)
	{
		if (lvl[i] > maxlvl)
		{
			maxlvl = lvl[i];
			mxlvIndex = i;
		}
	}
	cout <<"max lvl is :" maxlvl << " and index: " << mxlvIndex <<" to "<<mxlvIndex2<<endl;


}

#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define ull      unsigned ll
#define pii      pair<int, int>
#define pll      pair<ll, ll>
#define mp       make_pair
#define ff       first
#define ss       second
#define sz(x)    (int) x.size()
#define all(v)   v.begin(), v.end()

template <typename T> inline void smin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void smax(T &a, T b) {a = a > b ? a : b;}

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl;}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ", ";
	err(++it, args...);
}

template <typename T> inline void Int(T &n) {
	n = 0; int f = 1; register int ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
	n = n * f;
}

template <typename T, typename TT> inline void Int(T &n, TT &m) { Int(n); Int(m); }
template <typename T, typename TT, typename TTT> inline void Int(T &n, TT &m, TTT &l) { Int(n, m); Int(l); }

const int mod = (int) 1e9 + 7;

inline int add(int a, int b) {a += b; return a >= mod ? a - mod : a;}
inline int sub(int a, int b) {a -= b; return a < 0 ? a + mod : a;}
inline int mul(int a, int b) {return (ll) a * b % mod;}

const int inf = (int) 2e9 + 5;
const ll  Inf = (ll) 2e18 + 5;
const int N   = (int) 2e5 + 5;

int t = 0, k = 0;
vector<int> g[N], scc[N];
int low[N], d[N];
bool vis[N];
stack<int>ts;

void tarjan(int u) {
	vis[u] = true, ts.push(u), low[u] = d[u] = ++t;
	for (auto v : g[u]) {
		if (!d[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (vis[v]) {
			low[u] = min(low[u], d[v]);
		}
	}
	if (low[u] == d[u]) {
		int s;
		k++;
		do {
			s = ts.top();
			ts.pop();
			scc[k].push_back(s);
			vis[s] = false;
		} while (s != u and !ts.empty());
	}
}

int get_result(int n) {
	for (int i = 1; i <= n; i++) {
		if (!d[i]) tarjan(i);
	}
	return k;
}

int solve() {
	int n, m; Int(n, m);
	for (int i = 1; i <= m; i++) {
		int u, v; Int(u, v);
		g[u].push_back(v);
	}
	int k = get_result(n);
	printf("%d\n", k);
	for (int i = 1; i <= k; i++) {
		sort(all(scc[i]));
		for (int j = 0; j < sz(scc[i]); j++) {
			if (j) printf(" %d", scc[i][j]);
			else printf("%d", scc[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test = 1, tc = 0;
	//Int(test);
	//cin >> test;
	while (test--) {
		//printf("Case %d: ", ++tc);
		solve();
	}
	return 0;
}

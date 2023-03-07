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

vector<pii> g[N];
ll dis[N];
int par[N];

bool bellman_ford(int n, int s) {
	dis[s] = 0;
	for (int i = 1; i <= n; i++) {
		for (int u = 1; u <= n; u++) {
			for (auto x : g[u]) {
				int v = x.ff;
				ll w = (ll)x.ss;
				if (dis[v] > dis[u] + w) {
					if (i == n) return false;
					dis[v] = dis[u] + w;
					par[v] = u;
				}
			}
		}
	}
	return true;
}

void path(int u, int v) {
	if (par[v]) path(u, par[v]);
	if (u == v) printf("%d", v);
	else printf(" %d", v);
}

int solve() {
	int n, m; Int(n, m);
	for (int i = 0; i < m; i++) {
		int u, v, w; Int(u, v, w);
		g[u].push_back({v, w});
	}
	int s, q; Int(s, q);
	if (bellman_ford(n, s)) {
		while (q--) {
			int d; Int(d);
			if (dis[d] == Inf) {
				printf("Infinite\n");
			}
			else {
				printf("%lld\n", dis[d]);
				path(s, d);
				printf("\n");
			}
		}
	}
	else printf("Negative Cycle Exists\n");
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
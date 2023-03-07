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

std::vector<int> g[N];
int n1, n2, m;
int match_l[N], match_r[N];
int dis[N];
int s;

int bfs() {
	queue<int> q;
	for (int i = 1; i <= n1; i++) {
		if (match_l[i] == s) {
			dis[i] = 0;
			q.push(i);
		}
		else {
			dis[i] = inf;
		}
	}
	dis[s] = inf;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (dis[u] < dis[s]) {
			for (int v : g[u]) {
				if (dis[match_r[v]] == inf) {
					dis[match_r[v]] = dis[u] + 1;
					q.push(match_r[v]);
				}
			}
		}
	}
	return dis[s] < inf ? 1 : 0;
}

int dfs(int u) {
	if (u == s) return 1;
	for (int v : g[u]) {
		if (dis[match_r[v]] == dis[u] + 1) {
			if (dfs(match_r[v])) {
				match_r[v] = u;
				match_l[u] = v;
				return 1;
			}
		}
	}
	dis[u] = inf;
	return 0;
}

int hopcroft() {
	for (int i = 1; i <= n1; i++) {
		match_l[i] = s;
	}
	for (int i = n1 + 1; i <= n1 + n2; i++) {
		match_r[i] = s;
	}
	int ans = 0;
	while (bfs()) {
		for (int i = 1; i <= n1; i++) {
			if (match_l[i] == s) {
				if (dfs(i)) {
					ans++;
				}
			}
		}
	}
	return ans;
}

int solve() {
	Int(n1, n2, m);
	for (int i = 0; i < m; i++) {
		int u, v; Int(u, v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	s = n1 + n2 + 1;
	printf("%d\n", hopcroft());
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

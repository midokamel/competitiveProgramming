#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define OO (oo*oo)
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

const int MAX = 1001;
int mem[MAX][3 * MAX];
vector<pair<int, int>> v;
int longestIncreasingSubsequence(int index, int load) {
	if (index == sz(v))return 0;
	int& rt = mem[index][load];
	if (~rt)return rt;
	rt = longestIncreasingSubsequence(index + 1, load);
	if (v[index].first <= load)
		rt = max(rt, 1 + longestIncreasingSubsequence(index + 1, min(load - v[index].first, v[index].second)));
	return rt;
}

int main() {
	run();
	int n;
	while (cin >> n, n) {
		clr(mem, -1);
		v = vii(n);
		sort(all(v));
		for (auto& it : v) cin >> it.first >> it.second;
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, 1 + longestIncreasingSubsequence(i + 1, v[i].second));
		cout << ans << endl;
	}
}

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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

const int MAX = 1001;
int mem[MAX][MAX];
vector<int> v;
int longestIncreasingSubsequence(int index, int last) {
	if (index == sz(v))return 0;
	int& rt = mem[index][last];
	if (~rt)return rt;
	rt = longestIncreasingSubsequence(index + 1, last);
	if (last == sz(v) || v[last] < v[index])
		rt = max(rt, 1 + longestIncreasingSubsequence(index + 1, index));
	return rt;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		int n; cin >> n;
		v = vector<int>(n);
		for (auto& a : v)cin >> a;
		cout << longestIncreasingSubsequence(0, sz(v)) << endl;
	}
}

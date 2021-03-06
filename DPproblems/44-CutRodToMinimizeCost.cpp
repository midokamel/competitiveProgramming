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
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}
const int MAX = 101;
int mem[MAX][MAX];
vector<int> point;
int cutRod(int left, int right) {
	if (right < left)return 0;
	int start = point[left - 1], end = point[right + 1];
	if (right == left)return end - start;
	int& rt = mem[left][right];
	if (~rt)return rt;
	rt = oo;
	for (int k = left; k <= right; k++)
		rt = min(rt, cutRod(left, k - 1) + cutRod(k + 1, right));
	return rt += end - start;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		int l, n;
		cin >> n >> l;
		point = vector<int>(n + 1);
		for (int i = 1; i <= n; i++) cin >> point[i];
		point.push_back(l);
		cout << cutRod(1, n) << endl;
	}
}

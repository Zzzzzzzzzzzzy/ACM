#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int len;
ll f[20][50][2600];
int a[100],cnt[100],bac[3000],g[300];

int gcd(int a,int b) { return b == 0 ? a : gcd(b , a % b); }

ll dfs(int res,int id,int mod,int lim) {
	if (!lim && f[res][id][mod] != -1) return f[res][id][mod];
	if (res == 0) return mod % g[id] == 0;
	int pos = len - res + 1;
	int up = lim ? a[pos] : 9;
	ll ans = 0;
	for (int i = 0; i <= up; i++) {
		int add = 0;
		if (!cnt[i]) add = i;
		cnt[i]++;
		int now = add ? bac[g[id] * add / gcd(g[id] , add)] : id;
		ans += dfs(res - 1 , now , (mod * 10 + i) % 2520 , lim & i == a[pos]);
		cnt[i]--;
	}
	if (!lim) f[res][id][mod] = ans;
	return ans;
} 

ll solve(ll n) { 
	len = 0;
	while (n) { 
		a[++len] = n % 10;
		n /= 10;
	} 
	reverse(a + 1 , a + 1 + len);
	memset(cnt , 0 , sizeof(cnt));
	return dfs(len , 1 , 0 , 1);
} 

void init() { 
	int n = 10;
    set <int> s;
    for (int i = 0; i < (1 << n); i++) {
        int g = 1;
        for (int j = 1; j <= 9; j++)
            if (i & (1 << j)) g = g * j / __gcd(g , j);
        s.insert(g); 
    } 
    int cnt = 0;

    for (auto u : s) { 
    	g[++cnt] = u;
    	bac[u] = cnt;
    } 
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	int t; cin >> t;
	memset(f , -1 , sizeof(f));
	while (t--) { 
		ll l,r; cin >> l >> r;
		cout << solve(r) - solve(l - 1) << endl;
	} 
} 

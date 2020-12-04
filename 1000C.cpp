#include <cstdio>
#include <map>
#define ll long long
using namespace std;

const int maxn = 2e5;

ll num[maxn + 11];
map <ll,int> mp;

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		ll x,y;
		scanf("%lld %lld",&x,&y);
		mp[x]++;
		mp[y + 1]--;
	}
	map <ll,int>::iterator iter;
	iter = mp.begin();
	ll last = iter->first;
	int cnt = iter->second;
	iter++;
	while (iter != mp.end()){
		num[cnt] += iter->first - last;
		last = iter->first;
		cnt += iter->second;
		iter++;
	}
	for (int i = 1; i < n; i++) printf("%lld ",num[i]);
	printf("%lld\n",num[n]);
	return 0;
}

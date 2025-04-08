#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD	1000000007
using namespace std;
typedef long long int ll;
typedef pair<int,int> pp;

ll d, p;
ll ans = -1;

void solv(ll now, ll rest, ll lst) {
	if (now >= pow(10, d)) return;
	if (rest == 0) ans = max(ans, now);
	for (ll i = 2; i <= lst; i++) {
		solv(now * i, rest - 1, i);
	}
	return;
}

int main() {
	inp;
	cin >> d >> p;
	solv(1, p, 9);
	cout << ans;
}

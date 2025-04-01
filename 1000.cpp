#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD	1000000007
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> p;

struct compare {
	bool operator()(p &a, p &b) {
		return a.second < b.second;
	}
};

ll n, k;
vector<p> v;
vector<ll> bag;
priority_queue<p, vector<p>, compare> pq;

int main() {
	inp;
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		ll a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (ll i = 1; i <= k; i++) {
		ll a;
		cin >> a;
		bag.push_back(a);
	}

	sort(v.begin(), v.end(), [](const p& a, const p& b) {
		return a.first < b.first;
		});
	sort(bag.begin(), bag.end(), [](const ll& a, const ll& b) {
		return a < b;
		});
	ll ans = 0;
	ll now = 0;
	for (ll i = 0; i < k; i++) {
		if(now < n)
			while (v[now].first <= bag[i]) {
				pq.push(v[now]);
				now++;
				if (now >= n)break;
			}
		if (!pq.empty()) {
			ans += pq.top().second;
			pq.pop();
		}
	}
	cout << ans;
}
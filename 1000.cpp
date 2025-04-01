#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD	1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> p;


int n;
vector<p> j;
int l, pp;
priority_queue<int> pq;

int main() {
	inp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		j.push_back({ a,b });
	}

	cin >> l >> pp;
	j.push_back({ l,0 });
	sort(j.begin(), j.end(), [](const p& a, const p& b) {
		return a.first < b.first;
		});

	int ans = 0;
	int lst = -1;
	while (pp < l) {
		ans++;
		for (int i = lst + 1; j[i].first <= pp; i++) {
			pq.push({ j[i].second });
			lst = i;
		}
		if (pq.empty()) {
			cout << "-1";
			return 0;
		}
		pp += pq.top();
		pq.pop();
	}
	cout << ans;

}
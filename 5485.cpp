#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD	1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> p;


int main() {
	inp;

	int n;
	cin >> n;
	int lst = 0;
	int now = 0;
	int mn = -2147483644;
	int mx = 2147483644;
	cin >> lst;
	mx = lst;
	int k = lst;
	n--;
	for (int i = 0; i < n; i++) {
		cin >> now;
		if (i & 1) {
			mx = min(mx, k + (now - lst));
			k += (now - lst);
		}
		else {
			mn = max(mn, k + (lst - now));
			k += (lst - now);
		}
		lst = now;
	}

	cout << max(mx - mn + 1,0);

}

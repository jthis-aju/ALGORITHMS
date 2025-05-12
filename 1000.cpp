#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD	1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> p;


int main() {
	inp;

	int mx;
	int sam = 1;
	cin >> mx;
	int mn = mx;
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a < mx) mx++;
		if (a == mx) sam++;
		else if (a > mx && a < mx + sam) {
			sam = sam - a + mx + 1;
			mx = a;
		}
		if (a <= mn) mn++;
	}
	cout << mx << " " << mn;

}
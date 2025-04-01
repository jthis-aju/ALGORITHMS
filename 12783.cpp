#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD	1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> p;

int asdf;
int n;
int m;
int k;
bool isin[10];

bool can(int a) {
	while (a) {
		if (!isin[a % 10])return false;
		a /= 10;
	}
	return true;
}

int cnt(int a) {
	int mn = 88888888;
	if (can(a))return 0;
	for (int i = 2; i <= sqrt(a); i++) {
		if ((a / i) * i == a) {
			if (can(i)) {
				mn = min(mn, cnt(a / i) + 1);
			}
		}
	}
	return mn;
}

int main() {
	inp;
	cin >> asdf;
	while (asdf--) {
		for (int i = 0; i <= 9; i++)isin[i] = false;
		cin >> n;
		int a;
		while (n--) { cin >> a; isin[a] = true; }
		cin >> m;
		int b;
		
		while (m--) { cin >> b; int c = cnt(b); cout << (c < 88888888 ? c : -1) << endl; }
	}

}

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define f first
#define s second

//debug function
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

//define type
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

//infinity values
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	ll x = 10;
	ll y = 20;
	dbg(x);
	dbg(y);

	int initial_size = 10;
	int initial_value = 0;
	vector<int> v(initial_size, initial_value);

	pii p = {0, 1};
	int first = p.f;
	int second = p.s;

	dbg(first);
	dbg(second);

	return 0;
}

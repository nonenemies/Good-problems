#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>

using namespace std;

#define ll long long

ll power(ll a, ll b) {
    if (b == 0) return 1;
    ll res = 1;
    for (ll i = 1; i <= b; i++) {
        res *= a;
    }
    return res;
}

void solve() {
    ll n, p;
    cin >> n >> p;
    vector<pair<ll, ll>> v;
    ll cnt = 0;
    for (ll pos = 2; pos*pos <= p; pos++) {
        cnt = 0;
        while (p%pos==0) {
            p /= pos;
            cnt++;
        }
        if (cnt > 0) {
            v.push_back({pos, cnt});
        }
    }
    if (p>1) {
        v.push_back({p, 1});
    }
    ll ans = 1;
    for (ll i = 0; i < v.size(); ++i) {
        ans *= power(v[i].first, (v[i].second/n));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tc;cin >> tc;while (tc--) {solve();}
    solve();
    return 0;
}
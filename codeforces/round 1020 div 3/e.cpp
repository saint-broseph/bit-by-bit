#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define fo(i, k, n) for (ll i = k; i < n; i++)

void solve() {
    ll n, q;
    cin >> n >> q;
    vll p(n + 1), pos(n + 1);
    fo(i, 1, n + 1) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    while (q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        ll pk = pos[k];
        if (pk < l || pk > r) {
            cout << -1 << endl;
            continue;
        }
        ll L = l, R = r;
        bool prk = false;
        ll wc = 0;
        while (L <= R) {
            ll m = (L + R) / 2;
            if (m == pk) {
                prk = true;
                break;
            }
            if (m < pk) {
                if (p[m] > k) wc++;
                L = m + 1;
            } else {
                if (p[m] < k) wc++;
                R = m - 1;
            }
        }

        if (!prk) {
            cout << -1 << endl;
        } else {
            cout << wc << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

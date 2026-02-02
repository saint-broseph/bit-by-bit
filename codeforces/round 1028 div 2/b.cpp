#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define fo(i, k, n) for (ll i = k; i < n; i++)
#define all(v) v.begin(), v.end()

const ll MOD = 998244353;

ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    vll p(n), q(n);
    vll pos_p(n), pos_q(n);
    
    fo(i, 0, n) {
        cin >> p[i];
        pos_p[p[i]] = i;
    }
    fo(i, 0, n) {
        cin >> q[i];
        pos_q[q[i]] = i;
    }

    vll pref_p(n), pref_q(n);
    pref_p[0] = p[0];
    fo(i, 1, n) pref_p[i] = max(pref_p[i - 1], p[i]);
    pref_q[0] = q[0];
    fo(i, 1, n) pref_q[i] = max(pref_q[i - 1], q[i]);
    fo(i, 0, n) {
        ll max_exp = max(pref_p[i], pref_q[i]);
        ll other_val = 0;
        ll best_val = 0;
        ll idx1 = pos_p[pref_p[i]];
        if (idx1 <= i) {
            best_val = (binpow(2, p[idx1]) + binpow(2, q[i - idx1])) % MOD;
        }
        ll idx2 = pos_q[pref_q[i]];
        if (idx2 <= i) {
            ll current_j = i - idx2;
            ll val2 = (binpow(2, p[current_j]) + binpow(2, q[idx2])) % MOD;
            ll m1 = max(p[idx1], q[i-idx1]), n1 = min(p[idx1], q[i-idx1]);
            ll m2 = max(p[current_j], q[idx2]), n2 = min(p[current_j], q[idx2]);
            if (m2 > m1 || (m2 == m1 && n2 > n1)) {
                best_val = val2;
            }
        }

        cout << best_val << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

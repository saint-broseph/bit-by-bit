#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define fo(i, k, n) for (ll i = k; i < n; i++)
#define all(v) v.begin(), v.end()

const ll B = 320; 

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n + 1);
    fo(i, 1, n + 1) cin >> a[i];

    static vll pref1[B + 1], pref2[B + 1];
    fo(d, 1, min(B + 1, n + 1)) {
        pref1[d].assign(n + 1, 0);
        pref2[d].assign(n + 1, 0);
        fo(i, 1, n + 1) {
            pref1[d][i] = a[i];
            pref2[d][i] = a[i] * ((i + d - 1) / d); 
            if (i > d) {
                pref1[d][i] += pref1[d][i - d];
                pref2[d][i] += pref2[d][i - d];
            }
        }
    }

    while (q--) {
        ll s, d, k;
        cin >> s >> d >> k;
        if (d > B) {
            ll res = 0;
            fo(i, 0, k) {
                res += a[s + i * d] * (i + 1);
            }
            cout << res << " ";
        } else {
            ll last = s + (k - 1) * d;
            ll sum1 = pref1[d][last];
            ll sum2 = pref2[d][last];
            if (s > d) {
                sum1 -= pref1[d][s - d];
                sum2 -= pref2[d][s - d];
            }
            ll weight_at_s = (s + d - 1) / d;
            ll res = sum2 - (weight_at_s - 1) * sum1;
            cout << res << " ";
        }
    }
    cout << endl;
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

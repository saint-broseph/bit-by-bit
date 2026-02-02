#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define fo(i, k, n) for (ll i = k; i < n; i++)

struct Op {
    ll x, y, z;
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vll b(n + 1);
    fo(i, 1, n + 1) cin >> b[i];

    vector<Op> ops(q);
    fo(i, 0, q) {
        cin >> ops[i].x >> ops[i].y >> ops[i].z;
    }
    vll c = b; 
    vll current = b; 
    vll a = b;
    bool possible = true;
    vll sim = b; 
    fo(i, 0, q) {
        sim[ops[i].z] = min(sim[ops[i].x], sim[ops[i].y]);
    }
    
    fo(i, 1, n + 1) {
        if (sim[i] != b[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        fo(i, 1, n + 1) cout << b[i] << (i == n ? "" : " ");
        cout << "\n";
    } else {
        cout << "-1\n";
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

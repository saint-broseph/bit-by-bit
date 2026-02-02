#include <bits/stdc++.h>
using namespace std;
using dbl = double;
using ll = long long;
using str = string;
using ch = char;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using mpll = map<ll, ll>;
using vpll = vector<pll>;
using maxheap = priority_queue<ll>;
using minheap = priority_queue<ll, vll, greater<ll>>;

#define eb emplace_back
#define fo(i, k, n)  \
   for (ll i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tin(a, n) fo(i, 0, n) cin >> a[i]
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define f first
#define s second

void solve()
{
    ll n, m;
    cin >> n >> m;
    vll a(n + 1), b(m + 1);
    fo(i, 1, n + 1) cin >> a[i];
    fo(i, 1, m + 1) cin >> b[i];
    vll pre(m + 2, n + 1), suf(m + 2, n + 1);
    ll cur = 1;
    pre[0] = 0;
    fo(i, 1, m + 1) {
        while (cur <= n && a[cur] < b[i]) cur++;
        if (cur <= n) {
            pre[i] = cur;
            cur++;
        } else {
            pre[i] = n + 1;
        }
    }

    if (pre[m] <= n) {
        cout << 0 << "\n";
        return;
    }
    cur = n;
    suf[m + 1] = n + 1;
    fo(i, m, 0) {
        while (cur >= 1 && a[cur] < b[i]) cur--;
        if (cur >= 1) {
            suf[i] = cur;
            cur--;
        } else {
            suf[i] = 0;
        }
    }

    ll min_k = -1;
    fo(i, 1, m + 1) {
        if (pre[i - 1] < suf[i + 1]) {
            if (min_k == -1 || b[i] < min_k) {
                min_k = b[i];
            }
        }
    }

    cout << min_k << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

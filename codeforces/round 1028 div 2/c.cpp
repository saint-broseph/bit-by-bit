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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    ll global_gcd = 0;
    ll count_g = 0;
    fo(i, 0, n) {
        cin >> a[i];
        if (i == 0) global_gcd = a[i];
        else global_gcd = gcd(global_gcd, a[i]);
    }
    fo(i, 0, n) {
        if (a[i] == global_gcd) count_g++;
    }
    if (count_g > 0) {
        cout << n - count_g << "\n";
        return;
    }
    ll min_len = 1e18;
    fo(i, 0, n) {
        ll current_gcd = a[i];
        fo(j, i + 1, n) {
            current_gcd = gcd(current_gcd, a[j]);
            if (current_gcd == global_gcd) {
                min_len = min(min_len, j - i + 1);
                break; 
            }
        }
    }
    cout << (min_len - 1) + (n - 1) << "\n";
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

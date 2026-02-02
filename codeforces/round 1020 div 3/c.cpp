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
ll binpow(ll a, ll b, ll m)
{ // a^b MOD m
    a %= m;
    ll rem = 1;
    while (b > 0)
    {
        if (b & 1)
            rem = rem * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return rem;
}

const ll MOD = 1e9 + 7;
ll mod_add(ll a, ll b) { return (a + b) % MOD; }
ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return (a * b) % MOD; }
ll mod_inv(ll a) { return binpow(a, MOD - 2, MOD); } // FERMAT'S LITTLE THEOREM

ll combinations(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k;
    ll res = 1;
    for (ll i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

//Sieve and Prime factorization
const ll MAXP = 1000005;
ll min_prime[MAXP];
void sieve() {
    iota(min_prime, min_prime + MAXP, 0);
    for (ll i = 2; i * i < MAXP; i++) {
        if (min_prime[i] == i) {
            for (ll j = i * i; j < MAXP; j += i)
                if (min_prime[j] == j) min_prime[j] = i;
        }
    }
}
vll get_factors(ll n) {
    vll res;
    while (n > 1) {
        res.eb(min_prime[n]);
        n /= min_prime[n];
    }
    return res;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vll a(n), b(n);
    tin(a, n);
    tin(b, n);

    ll L = -1e18, R = 1e18;
    ll fixed_x = -1;
    bool possible = true;

    fo(i, 0, n) {
        L = max(L, a[i]);
        R = min(R, a[i] + k);
        if (b[i] != -1) {
            ll x = a[i] + b[i];
            if (fixed_x != -1 && fixed_x != x) {
                possible = false;
            }
            fixed_x = x;
        }
    }

    if (!possible) {
        cout << 0 << "\n";
        return;
    }

    if (fixed_x != -1) {
        if (fixed_x >= L && fixed_x <= R) cout << 1 << "\n";
        else cout << 0 << "\n";
    } else {
        ll ways = max(0LL, R - L + 1);
        cout << ways << "\n";
    }
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

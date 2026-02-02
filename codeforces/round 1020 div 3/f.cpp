#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using vll = vector<ll>;

#define fo(i, k, n) for (ll i = k; i < n; i++)

void solve()
{
    ll n;
    cin >> n;
    str s;
    cin >> s;

    ll total_zeros_in_s = 0;
    for(char c : s) if(c == '0') total_zeros_in_s++;
    if (total_zeros_in_s == 0) {
        cout << 1 << "\n";
        return;
    }
    ll native_zero_cells = n * total_zeros_in_s - total_zeros_in_s;
    ll flipped_zeros_connected = 0;
    fo(i, 0, n) {
        if (s[i] == '1') {
            bool connects = false;
            if (i > 0 && s[i - 1] == '0') connects = true;
            if (i < n - 1 && s[i + 1] == '0') connects = true;
            
            if (connects) flipped_zeros_connected++;
        }
    }    
    cout << native_zero_cells + flipped_zeros_connected << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

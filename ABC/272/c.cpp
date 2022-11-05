#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> odd, even;
    rep(i, N) {
        ll a; cin >> a;
        if (a % 2 == 0) even.push_back(a);
        else odd.push_back(a);
    }

    int o = odd.size(), e = even.size();

    if (o < 2 && e < 2) cout << -1 << endl;
    else {
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        ll a;
        if (o < 2) a = 0;
        else a = odd[o - 1] + odd[o - 2];

        ll b;
        if (e < 2) b = 0;
        else b = even[e - 1] + even[e - 2];
        
        cout << max(a, b) << endl;
    }
}
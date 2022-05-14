#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<pair<ll, ll>> V(N);
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        V.at(i) = {x, y};
    }
    set<pair<ll, ll>> ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            ll xi, yi, xj, yj;
            tie(xi, yi) = V.at(i); tie(xj, yj) = V.at(j);
            ll dx = xj - xi, dy = yj - yi;
            if (dx != 0 && dy != 0) {
                ll n = gcd(dx, dy);
                ans.insert({dx / n, dy / n});
            }
            else if (dx == 0) {
                if (dy > 0) ans.insert({0, 1});
                else ans.insert({0, -1});
            }
            else if (dy == 0) {
                if (dx > 0) ans.insert({1, 0});
                else ans.insert({-1, 0});
            }
        }
    }
    cout << (int)ans.size() << endl;
}
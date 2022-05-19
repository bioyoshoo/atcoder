#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n ,c;
    cin >> n >> c;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A.at(i);

    ll ans = 1e6;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i == j) continue;
            ll cost = 0;
            for (int k = 0; k < n; k++) {
                if (k % 2 == 0 && A[k] != i) cost += c;
                else if (k % 2 == 1 && A[k] != j) cost += c;
            }
            ans = min(ans, cost);
        }
    }
    cout << ans << endl;
}
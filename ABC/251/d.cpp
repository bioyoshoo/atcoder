#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> eratos(ll N) {
    
    vector<bool> isprime(N + 1, true);
    isprime[1] = false;
    for (ll p = 2; p <= N; p++) {
        if (!isprime[p]) continue;
        for (ll q = 2 * p; q <= N; q += p) {
            isprime[q] = false;
        }
    }
    return isprime;
}


int main() {
    int W;
    cin >> W;

    vector<bool> res = eratos(W);
    ll num = 0;
    for (int n = 1; n <= W; n++) if (res[n]) num++;
    cout << num << endl;
}
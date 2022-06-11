#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n_digits(ll n) {
    return to_string(n).size();
}

vector<ll> V;
void DFS(ll n) {
    if (n_digits(n) >= 11) return;
    V.push_back(n);

    int m = n % 10;
    if (m != 0) DFS(10 * n + m - 1);
    DFS(10 * n + m);
    if (m != 9) DFS(10 * n + m + 1);
}

int main() {
    int K; cin >> K;

    for (int i = 1; i < 10; i++) DFS(i);

    sort(V.begin(), V.end());

    cout << V[K - 1] << endl;
}
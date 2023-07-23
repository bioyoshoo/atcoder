#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n_digit(ll n) {
    return (int)to_string(n).size();
}

vector<ll> res;
void DFS(ll n) {
    if (n_digit(n) == 10) {
        res.push_back(n);
        return;
    }

    DFS(10*n + 4);
    DFS(10*n + 7);
}

int main() {
    int N; cin >> N;
    DFS(0);
    sort(res.begin(), res.end());
    cout << res[N - 1] << endl;
}

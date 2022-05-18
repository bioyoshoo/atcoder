#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string X;
    cin >> X;
    int N = X.size();
    
    vector<ll> ans(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (int)(X[i] - '0');
        ans.at(i) = sum;
    }
    for (int i = N - 1; i >= 1; i--) {
        ans.at(i - 1) += ans.at(i) / 10;
        ans.at(i) = ans.at(i) % 10;
    }
    for (auto a: ans) cout << a;
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    int sum = 0;
    rep(i, N) {
        string s; cin >> s;
        if (s == "For") sum++;
    }

    if (sum >= (N + 1)/2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
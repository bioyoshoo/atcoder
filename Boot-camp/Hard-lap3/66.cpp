#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int N = S.size();
    string T;
    for (int i = 0; i < N;) {
        if (i + 1 < N && S[i] == 'B' && S[i + 1] == 'C') {
            T += 'D'; i += 2;
        }
        else {
            T += S[i]; i++;
        }
    }
    vector<string> V;
    for (int i = 0; i < N;) {
        if (T[i] == 'A' || T[i] == 'D') {
            int j = i + 1;
            while (j < N && (T[j] == 'A' || T[j] == 'D')) j++;
            V.push_back(T.substr(i, j - i));
            i = j;
        }
        else i++;
    }
    ll ans = 0;
    for (auto v: V) {
        int n = v.size();
        vector<int> c(n);
        rep(i, n) if (v[i] == 'D') c[i] = 1;
        for (int i = n - 2; i >= 0; i--) c[i] += c[i + 1];
        rep(i, n) if (v[i] == 'A') ans += c[i];
    }
    cout << ans << endl;
}
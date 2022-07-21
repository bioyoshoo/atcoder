#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll f(string s) {
    ll res = 0;
    for (auto c: s) res += (ll)(c - '0');
    return res;
}

string check(string s, string t) {
    int n = s.size(), m = t.size();
    if (n < m) return s;
    else if (n > m) return t;
    else {
        for (int i = 0; i < n; i++) {
            if (s[i] < t[i]) return s;
            else if (s[i] > t[i]) return t;
        }
    }
}

int main() {
    ll N; cin >> N;

    ll M = 2*N;

    int num4 = N / 4;
    N %= 4;
    int num3 = N / 3;
    N %= 3;
    int num2 = N / 2;
    int num1 = N % 2;

    string cand = "";
    for (int i = 0; i < num1; i++) cand += '1';
    for (int i = 0; i < num2; i++) cand += '2';
    for (int i = 0; i < num3; i++) cand += '3';
    for (int i = 0; i < num4; i++) cand += '4';

    // N 1桁 x = N 
    string ans = "";
    if ((f(to_string(N)) == N) && (f(to_string(2*N)) == M)) ans = check(cand, to_string(N));
    else ans = cand;

    cout << M << endl;
    cout << ans << endl;
}
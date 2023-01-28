#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    char c; cin >> c;
    string A; cin >> A;

    map<char, int> mp;
    rep(i, N) mp[A[i]] += 1;

    char last;
    int mod;
    if (mp['B'] >= mp['R']) {
        mod = (mp['B'] - mp['R']) % 3;

        if (mod == 0) last = 'W';
        else if (mod == 1) last = 'B';
        else if (mod == 2) last = 'R';
    }
    else {
        mod = (mp['R'] - mp['B']) % 3;

        if (mod == 0) last = 'W';
        else if (mod == 1) last = 'R';
        else if (mod == 2) last = 'B';
    }

    if (last == c) cout << "Yes" << endl;
    else cout << "No" << endl;
}
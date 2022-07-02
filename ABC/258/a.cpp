#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

string pad(int n) {
    string n_s = to_string(n);
    if (n_s.size() == 1) n_s = "0" + n_s;
    return n_s;
}
int main() {
    int K; cin >> K;

    int time = 21 + (K / 60);
    int min = K % 60;
    string t = pad(time), m = pad(min);
    cout << t << ":" << m << endl;
}
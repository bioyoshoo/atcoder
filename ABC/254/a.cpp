#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)


int main() {
    int N;
    cin >> N;
    string n_s = to_string(N);
    int size = n_s.size();
    string ans = n_s.substr(size - 2, 2);
    cout << ans << endl;
}
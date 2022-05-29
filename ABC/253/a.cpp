#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    string ans;
    if (a <= b && b <= c) ans = "Yes";
    else if (c <= b && b <= a) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
}
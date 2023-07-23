#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int a, b; cin >> a >> b;
    
    if (b - a == 1) cout << "Yes" << endl;
    else if (abs(a % 10 - b % 10) == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}

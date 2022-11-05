#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    double A, B; cin >> A >> B;
    double C = B / A;

    // int c = (int)(C * 10000) % 10;
    // if (c >= 5) C += 0.001;
    
    
    cout << fixed << setprecision(3);
    cout << C << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll X; cin >> X;

    bool flag = false;
    for (ll a = -200; a <= 200; a++) {
        for (ll b = -200; b <= 200; b++) {
            ll a5 = a*a*a*a*a, b5 = b*b*b*b*b;
            if (a5 - b5 == X) {
                cout << a << " " << b << endl;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
}
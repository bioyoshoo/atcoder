#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> V(b, 0);
    for (int n = 1; n <= b; n++) V[n - 1] = n * a % b;

    bool flag = false;
    for (int i = 0; i < b; i++) {
        if (V[i] == c) {
            flag = true;
            break;
        }
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
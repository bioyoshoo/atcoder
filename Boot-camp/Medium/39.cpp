#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main() {
    unsigned long long K, A, B;
    cin >> K >> A >> B;

    unsigned long long ans;
    if (B > A + 2) ans = ((K + 1) / (A + 2)) * B + ((K + 1) % (A + 2));
    else ans = K + 1;

    cout << ans << endl;
}
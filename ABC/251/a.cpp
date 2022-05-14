#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int n = S.size();

    string ans = "";
    for (int i = 0; i < 6; i++) {
        ans += S[i % n];
    }
    cout << ans << endl;
}
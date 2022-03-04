#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int64_t ans = 0;
    for (int i = 1; i < (int)S.size(); i++) {
        if (S.at(i - 1) != S.at(i)) ans++;
    }

    cout << ans << endl;
}
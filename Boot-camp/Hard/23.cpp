#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    reverse(S.begin(), S.end());

    bool ans = true;
    int length = (int)S.size();
    while (ans && length > 0) {
        if (S.substr(0, 7) == "remaerd") S = S.substr(7);
        else if (S.substr(0, 5) == "maerd") S = S.substr(5);
        else if (S.substr(0, 6) == "resare") S = S.substr(6);
        else if (S.substr(0, 5) == "esare") S = S.substr(5);
        else ans = false;
        length = (int)S.size();
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}
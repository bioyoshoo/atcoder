#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, a, b;
    cin >> S;
    int Q;
    cin >> Q;
    int cnt1 = 0;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) cnt1++;
        else if (t == 2) {
            int f;
            char c;
            cin >> f >> c;
            if ((cnt1 % 2 == 0 && f == 1) || (cnt1 % 2 == 1 && f == 2)) a = c + a;
            else if ((cnt1 % 2 == 0 && f == 2) || (cnt1 % 2 == 1 && f == 1)) b = b + c;
        }
    }
    S = a + S + b;
    if (cnt1 % 2 == 0) cout << S << endl;
    else {
        reverse(S.begin(), S.end());
        cout << S << endl;
    }
}
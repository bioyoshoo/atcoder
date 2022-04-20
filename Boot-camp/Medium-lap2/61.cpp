#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int q;
    cin >> q;
    int reverse_cnt = 0;
    string a = "", b = "";
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) reverse_cnt = 1 - reverse_cnt;
        else if (t == 2) {
            int f;
            char c;
            cin >> f >> c;
            if (reverse_cnt == 0) {
                if (f == 1) a = c + a;
                else if (f == 2) b = b + c;
            }
            else if (reverse_cnt == 1) {
                if (f == 1) b = b + c;
                else if (f == 2) a = c + a;
            }
        }
    }
    S = a + S + b;
    if (reverse_cnt == 1) reverse(S.begin(), S.end());
    cout << S << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int N = S.size();

    int ans = 0;
    int i = 0, j = N - 1;
    while (j - i > 0) {
        if (S[i] == S[j]) {
            i++;
            j--;
        }
        else {
            if (S[i] == 'x') {
                ans++;
                i++;
            }
            else if (S[j] == 'x') {
                ans++;
                j--;
            }
            else {
                ans = -1;
                break;
            }
        }
    }
    cout << ans << endl;
}
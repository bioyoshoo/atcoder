#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int N = S.size();
    
    int ans = 0;
    for (int i = 0; i < N;) {
        if (i + 1 < N && S[i] != S[i + 1]) {
            ans++;
            i++;
        }
        else if (i + 3 < N && S[i] == S[i + 1]) {
            ans += 2;
            i += 3;
        }
        else if (i + 1 < N && S[i] == S[i + 1]) {
            ans++;
            i += 2;
        }
        else if (i == N - 1) {
            ans++;
            i++;
        }
    }
    
    cout << ans << endl;
}
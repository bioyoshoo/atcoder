#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    string T = "";
    for (int i = 0; i < (int)S.size();) {
        if (S[i] == 'B' && S[i + 1] == 'C') {
            T += 'D';
            i += 2;
        }
        else {
            T += S[i];
            i++;
        }
    }

    vector<string> V;
    for (int i = 0; i < (int)T.size();) {
        if (T[i] == 'A') {
            int j = i;
            while (T[j] == 'A' || T[j] == 'D') j++;
            if (j - i > 1) V.push_back(T.substr(i, j - i));
            i = j;
        }
        else i++;
    }

    int64_t ans = 0;
    for (string v: V) {
        int n = v.size();
        vector<int> vec(n, 0);
        for (int i = 0; i < n; i++) if (v[i] == 'D') vec[i] = 1;
        for (int i = n - 2; i >= 0; i--) vec[i] += vec[i + 1];
        for (int i = 0; i < n; i++) if (v[i] == 'A') ans += vec[i];
    }
    cout << ans << endl;
}
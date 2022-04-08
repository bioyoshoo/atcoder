#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> S(M), C(M);
    for (int i = 0; i < M; i++) {
        int s, c;
        cin >> s >> c;
        s--;
        S.at(i) = s; C.at(i) = c;
    }

    string ans = "";
    for (int n = 0; n < 1000; n++) {
        string n_s = to_string(n);
        
        if ((int)n_s.size() != N) continue;

        bool flag = true;
        for (int i = 0; i < M; i++) {
            if ((n_s[S[i]] - '0') != C[i]) flag = false;
        }
        
        if (flag) {
            ans = n_s;
            break;
        }
    }

    if (ans == "") ans = "-1";
    cout << ans << endl;
}
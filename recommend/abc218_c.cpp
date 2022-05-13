#include <bits/stdc++.h>
using namespace std;

vector<string> rotate(vector<string> table) {
    int n = table.size();
    vector<string> res(n, string(n, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j][n - i - 1] = table[i][j];
        }
    }
    return res;
}

vector<string> normalize(vector<string> table) {
    int n = table.size();
    int min_i = n, min_j = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == '#') {
                min_i = min(min_i, i);
                min_j = min(min_j, j);
            }
        }
    }
    vector<string> res(n, string(n, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == '#') res[i - min_i][j - min_j] = '#';
        }
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    for (int i = 0; i < N; i++) cin >> S.at(i);
    for (int i = 0; i < N; i++) cin >> T.at(i);

    bool ans = false;
    for (int r = 0; r < 4; r++) {
        S = rotate(S);
        if (normalize(S) == normalize(T)) {
            ans = true;
            break;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}